#include <stdio.h>

int a = 2;
int b = 5;

int sum(const int *ptrA, const int *ptrB, int *ptrResult){
    *ptrResult = *ptrA + *ptrB;
}
int subtraction(const int *ptrA, const int *ptrB, int *ptrResult){
    *ptrResult = *ptrA - *ptrB;
}
int multiplication(const int *ptrA, const int *ptrB, int *ptrResult){
    *ptrResult = *ptrA * *ptrB;
}
float division(const int *ptrA, const int *ptrB, float *ptrResult2){
    *ptrResult2 = *ptrA / *ptrB;
}


int main(void) {
    int a = 2;
    int b = 5;
    int result = 0;
    float result2 = 0;

    sum(&a, &b, &result);
    printf("%d + %d = %d\n", a, b, result);

    subtraction(&a, &b, &result);
    printf("%d - %d = %d\n", a, b, result);

    multiplication(&a, &b, &result);
    printf("%d * %d = %d\n", a, b, result);

    division(&a, &b, &result2);
    printf("%d / %d = %f\n", a, b, result2);

    return 0;
}
