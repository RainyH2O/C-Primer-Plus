#include <stdio.h>
#define SIZE 30

char *delept(char *);

int main(void)
{
    char str[SIZE];

    printf("Enter a string: ");
    while (gets(str) != NULL && str[0] != '\0')
    {
        if (delept(str) != NULL)
            puts(str);
        printf("Enter next string: ");
    }
    puts("Done!");

    return 0;
}

char *delept(char *str)
{
    int i = 0;
    int j;

    while (str[i] != '\0')
    {
        if (str[i] == ' ')
        {
            for (j = i; str[j] != '\0'; j++)
                str[j] = str[j+1];
            str[j] = '\0';
        }
        else
            i++;
    }

    return str;
}
