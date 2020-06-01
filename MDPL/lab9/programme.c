#include <stdio.h>
#include <string.h>
#define MAX_STR 100

int extract_int(const char* string) 
{
    char c;
    int digit,number = 0;
    for (int i = 0; i < strlen(string); i++)
    {
        c = string[i];
        if (c >= '0' && c <= '9')
        {
            digit = c - '0';
            number = number * 10 + digit;
        }
    }

    return number;
}

int main(void) 
{
    char string[MAX_STR];
    printf("Enter a String: ");
    fgets(string, sizeof(string), stdin);

    printf("Your String is: %s", string);

    int a = extract_int(string);
    printf("Extracted Number is: %d", a);

    return 0;
}