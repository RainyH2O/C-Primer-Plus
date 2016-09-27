#include <stdio.h>

void putch(char, int, int);

int main(void)
{
    char ch;
    int col, row;

    printf("Enter a characters and numbers of column and row(q to quit): ");
    while (scanf("%c %d %d", &ch, &col, &row) == 3)
    {
        putch(ch, col, row);
        printf("Enter a characters and numbers of column and row(q to quit): ");
    }
    printf("Bye!\n");

    return 0;
}

void putch(char ch, int i, int j)
{
    int m, n;
    for (m = 0; m < j; m++)
    {
        for (n = 0; n < i; n++)
            putchar(ch);
        putchar('\n');
    }
    return;
}
