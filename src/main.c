#include <stdio.h>
#include <stdlib.h>

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
            show(num1, m, n);

            p1--;
        } else {
            num1[p] = num2[p2];
            show(num1, m, n);
            p2--;
        }
        p--;
    }

    while(p2 >= 0){
        num1[p] = num2[p2];
        show(num1, m, n);

        p2--;
        p--;
    }

}

int main(void){
    //Case 1:
    int num1[] = {1,2,3,0,0,0};
    int num2[] = {2,5,6};
    int m = 3; int n = 3;

    merge(num1, m, num2, n);

    return 0;
}