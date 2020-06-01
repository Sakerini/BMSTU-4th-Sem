#include <stdio.h>
#include <string.h>
#define MAX_STR_LEN 100

void my_str_cpy(char *dest, const char *src, size_t size);

size_t my_str_len(const char *str)
{
    __asm__ (
        "xor rax, rax;"
        "mov rcx, -1;"
        "cld;"
        "repne scasb;"
        "not rcx;"
        "dec rcx;"
        "mov eax, ecx;"
    );
}

int main(void)
{
    printf("\n\n\n(HelloWorld)\nlib_strlen: %ld \nmy_strlen: %ld\n",strlen("HelloWorld"), my_str_len("HelloWorld"));

    char dest[MAX_STR_LEN];
    char src[] = "HelloWorld123";
    my_str_cpy(dest, src, strlen(src));

    printf("\nCopying %s to destination array\nDestination array: ", src);

    printf("%s\n\n", dest);
    return 0;
}