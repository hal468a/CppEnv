void show(int* nums, int numSize){
    for(int i = 0; i < numSize; i++){
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int removeElement(int* nums, int numsSize, int val){
    int cout = 0;

    return cout;
}

int main(void){

    // Case 1:
    int num1[] = {3,2,2,3}; // {2,2}
    int numSize = sizeof(num1) / sizeof(num1[0]);
    int target = 3;
    printf("%d ", removeElement(num1, numSize, target));

    // Case 2:
    int num2[] = {0,1,2,2,3,0,4,2}; // {0,1,4,0,3}
    numSize = sizeof(num2) / sizeof(num2[0]);
    target = 2;
    printf("%d ", removeElement(num2, numSize, target));

    return 0;
}