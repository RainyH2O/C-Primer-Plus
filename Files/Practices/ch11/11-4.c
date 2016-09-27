#include <stdio.h>
#define SIZE 30

const char *strchp(const char *, char);

int main(void)
{
    char arr[SIZE];
    char ch;
    const char * c;

    printf("Please enter a string: ");
    while (gets(arr) != NULL)
    {
        printf("Please enter a character: ");
        ch = getchar();

        c = strchp(arr, ch);
        if (c == NULL)
            printf("No this character!\n");
        else
            printf("Found the %c in %p\n", *c, c);
        printf("Please enter a string: ");
        gets(arr);
    }

    return 0;
}

const char *strchp(const char *str, char ch)
{
    while (*str != '\0' && *str != ch)
        str++;
    if (*str == ch)
        return str;
    else
        return NULL;
}
