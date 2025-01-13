#include <stdio.h>
#include <stdlib.h>

// LeetCode 88. Merge Sort Array

void show(int* nums, int m , int n){
    for(int i = 0; i < m + n; i++){
        printf("%d ", nums[i]);
    }
    printf("\n");
}

void merge(int* num1, int m, int* num2, int n){
    int p1 = m - 1;
    int p2 = n - 1;
    int p = m + n - 1;

    while(p1 >= 0 && p2 >= 0){
        if(num1[p1] >= num2[p2]){
            num1[p] = num1[p1];
            p1--;
        } else {
            num1[p] = num2[p2];
            p2--;
        }
        p--;
    }

    while(p2 >= 0){
        num1[p] = num2[p2];
        p2--;
        p--;
    }
}

int main(void){
    // Case 1:
    int num0[] = {1,2,3,0,0,0};
    int num1[] = {2,5,6};
    int m = 3; int n = 3;

    printf("Case 1: ");
    merge(num0, m, num1, n);
    show(num0, m, n);

    // Case 2:
    int num2[] = {1};
    int num3[] = {};
    m = 1; n = 0;

    printf("Case 2: ");
    merge(num2, m, num3, n);
    show(num2, m, n);

    // Case 3:
    int num4[] = {0};
    int num5[] = {1};
    m = 0; n = 1;

    printf("Case 3: ");
    merge(num4, m, num5, n);
    show(num4, m, n);

    return 0;
}