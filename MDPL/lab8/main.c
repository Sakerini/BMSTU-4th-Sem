#include <stdio.h>

float calculate(float a, float b, char math_sign);

int main(void) {

    float a,b,res;
    char math_sign;

    printf("Input format [a, math_sign, b] :");
    scanf("%f %c %f", &a, &math_sign, &b);

    res = calculate(a,b,math_sign);

    printf("%f %c %f = %f\n", a, math_sign, b, res);

}