#include<stdio.h>

float calculate(float a, float b, char math_sign) {
    float result = 0;
    if (math_sign == '+') {
        result = a + b;
    }
    else if (math_sign == '-') {
        result = a - b;
    }
    else if (math_sign == '*') {
        result = a * b;
    }
    else if (math_sign == '/') {
        result = a / b;
    }

    return result;
}

int main ()
{
    float a = 6;
    float b = 3;
    printf("%f %c %f = %f", a,'/',b,calculate(a,b,'/'));
    return 0;
}