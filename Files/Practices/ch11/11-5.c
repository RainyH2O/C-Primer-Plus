#include <stdio.h>
#define SIZE 30

int is_within(char, char *);

int main(void)
{
    char str[SIZE];
    char ch;

    printf("Please enter a string: ");
    while (gets(str) != NULL && str[0] != '\0')
    {
        printf("Please enter a character: ");
        ch = getchar();
        while (getchar() != '\n')
            continue;
        if (is_within(ch, str))
            printf("The character %c is in the string.\n", ch);
        else
            printf("The character %c isn't in the string.\n", ch);
        printf("Please enter next string: ");
    }
    puts("Done!");

    return 0;
}

int is_within(char ch, char *str)
{
    while (*str != '\0' && *str != ch)
        str++;
    return *str;
}
