#include <stdio.h>

void chline(char, int, int);

int main(void)
{
    char ch;
    int start, end;

    printf("Enter a characters and the start column and the end columns: ");
    while (scanf("%c %d %d", &ch, &start, &end) == 3)
    {
        chline(ch, start, end);
        printf("Enter a characters and the start column and the end columns: ");
    }
    printf("Bye!\n");

    return 0;
}

void chline(char ch, int i, int j)
{
    int n;

    for(n = 0; n < i - 1; n++)
        putchar(' ');
    for(n = 0; n <= j - i; n++)
        putchar(ch);
    putchar('\n');
}
