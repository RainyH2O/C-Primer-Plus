#include <stdio.h>
#define SIZE 30

char *rgets(char *);

int main(void)
{
    char str[SIZE];

    printf("Enter a string: ");
    while (rgets(str) != NULL && str[0] != '\0')
    {
        puts("String:");
        puts(str);
        printf("Enter next string: ");
    }
    puts("Done!");

    return 0;
}

char *rgets(char *str)
{
    char temp[SIZE];
    char * pt = str;
    int i = 0;

    while ((temp[i] = getchar()) != '\n' && temp[i] != EOF)
        i++;

        if (temp[i] == EOF)
            return NULL;
        for (i--; i >= 0; i--, pt++)
            *pt = temp[i];
        *pt = '\0';

        return str;
}
