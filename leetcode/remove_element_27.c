#include <stdio.h>
#include <stdlib.h>

void show(int* nums, int numSize){
    for(int i = 0; i < numSize; i++){
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int removeElement(int* nums, int numsSize, int val){
    int k = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] != val){
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}

int main(void){

    // Case 1:
    int num1[] = {3,2,2,3}; // {2,2}
    int numSize = sizeof(num1) / sizeof(num1[0]);
    int target = 3;

    int k = removeElement(num1, numSize, target);
    show(num1, k);

    // Case 2:
    int num2[] = {0,1,2,2,3,0,4,2}; // {0,1,4,0,3}
    numSize = sizeof(num2) / sizeof(num2[0]);
    target = 2;
    k = removeElement(num2, numSize, target);
    show(num2, k);

    return 0;
}