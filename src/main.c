#include <stdio.h>
#include <stdlib.h>

int main(void){

    int grade[] = {97, 96, 84, 81, 85, 91, 90, 90, 85};
    double gpa = 0.0;
    int numSize = sizeof(grade) / sizeof(grade[0]);

    for(int i = 0; i <= numSize; i++){
        grade[i] = grade[i] * 3;
        gpa = gpa + grade[i];
    }
    
    gpa = gpa / (numSize * 3);
    printf("%.2f", gpa);

    return 0;
}