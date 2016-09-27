#include <stdio.h>
#define SIZE 30

char * geta(char [], int);

int main(void)
{
    char arr[SIZE];
    int i;
    char * chk;

    chk = geta(arr, SIZE - 1);
    if (chk == NULL)
        puts("Input failed!");
    else
        puts(arr);

    return 0;
}

char * geta(char a[], int n)
{
    char ch;
    int i;

    for (i = 0; i < n; i++)
    {
        ch = getchar();
        if (ch != EOF)
            a[i] = ch;
        else
            break;
    }
    if (ch == EOF)
        return NULL;
    else
    {
        a[i] = '\0';
        return a;
    }
}
