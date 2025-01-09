#include <stdio.h>
void float_normal(void);
void kahan_sum(void);
float test(void);

int main () {
    float_normal();
    kahan_sum();

    printf("Test sum: %f\n", test());
    
    return 0;
}

void float_normal(void) {
    float sum = 0.0f;
    for (int i = 0; i < 10000; i++) {
        sum += i + 1;
    }
    printf("Normal Sum: %f\n", sum);
}

void kahan_sum(void) {
    float sum = 0.0f, corr = 0.0f;

    for (int i = 0; i < 10000; i++) {
        float current = i + 1; // 本輪實際要加的值
        // printf("current = %d + 1\n", i);

        float adjusted = current - corr; // 將要加的值減上輪的誤差進行校正
        // printf("adjusted = (%f - %f)\n", current, corr);

        float temp = sum + adjusted; // temp 負責儲存上一輪的sum + adjusted (校正後的)等於實際的sum
        // printf("temp = %f + %f\n", sum, adjusted);

        corr = (temp - sum) - adjusted; // 將本輪實際的sum(也就是temp)減掉上一輪的sum，再從這個差異中再減去本輪的adjusted，得到的就是本輪實際累加過程中產生的誤差，也就是本輪「遺失」的精度位。這個值儲存在 corr 中，用於下一輪迴圈時的誤差補償。
        // printf("corr = (%f - %f) - %f\n", temp, sum, adjusted);
        // printf("--------------------------------------------\n");

        sum = temp;
    }

    printf("Kahan Sum: %f\n", sum);
}

float test(void){
    float sum = 0.0f, corr = 0.0f;
    for(int i = 0; i < 10000; i++){
        float curr = i + 1;
        float adjusted = curr - corr;
        float temp = sum + adjusted;
        corr = (temp - sum) - adjusted;
        sum = temp;
    }

    return sum;
}