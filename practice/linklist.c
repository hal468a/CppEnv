#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insert(struct node** head, int data, int pos) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    
    if (pos == 0){
        new_node->next = *head;
        *head = new_node;
        return;
    }

    struct node* temp = *head;
        // 找到插入位置的前一個節點
        for (int i = 0; temp != NULL && i < pos - 1; i++) {
            temp = temp->next;
        }

        // 如果插入位置超過鏈結串列的長度
        if (temp == NULL) {
            printf("插入位置超出範圍\n");
            free(new_node);
            return;
        }

        // 在指定位置插入新節點
        new_node->next = temp->next;
        temp->next = new_node;
};

// 刪除鏈結串列中具有指定數據的第一個節點
void deleteNode(struct node** head_ref, int key) {
    struct node* temp = *head_ref;
    struct node* prev = NULL;

    // 如果要刪除的節點是頭節點
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; // 改變head
        free(temp); // 釋放頭節點
        return;
    }

    // 搜尋要刪除的節點
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // 如果找不到節點，返回
    if (temp == NULL) return;

    // 斷開鏈結並釋放內存
    prev->next = temp->next;
    free(temp);
};

// 顯示鏈結串列的內容
void printList(struct node* node) {
    while (node != NULL) {
        printf(" %d ", node->data);
        node = node->next;
    }
    printf("\n");
};

// 主函數
int main() {
    struct node* head = NULL;
    int data, position;

    // 插入幾個初始節點
    insert(&head, 10, 0);
    insert(&head, 20, 1);
    insert(&head, 30, 2);

    // 顯示初始鏈結串列
    printf("初始鏈結串列: ");
    printList(head);

    // 讓使用者指定插入的資料和位置
    printf("請輸入要插入的資料: ");
    scanf("%d", &data);
    printf("請輸入要插入的位置（從0開始）: ");
    scanf("%d", &position);

    // 插入資料
    insert(&head, data, position);

    // 顯示插入後的鏈結串列
    printf("插入後的鏈結串列: ");
    printList(head);

    return 0;
}