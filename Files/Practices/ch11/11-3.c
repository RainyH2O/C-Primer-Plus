#include <stdio.h>
#define SIZE 30

char * getw(char []);

int main(void)
{
    char * chk;
    char arr[SIZE];

    while ((chk = getw(arr)) != NULL)
        puts(arr);
    puts("Done!");

    return 0;
}

char * getw(char a[])
{
    char ch;

    while ((ch = getchar()) != EOF && ch != ' ' && ch != '\n' && ch != '\t')
        *a++ = ch;
    *a = '\0';
    if (ch == EOF)
        return NULL;
    else
    {
        while (ch != '\n')
            ch = getchar();
        return a;
    }
}
