#include <stdio.h>

int main(void)
{
    int row, empty;
    char end, start;
    const char LET = 'A';

    printf("Enter a uppercase letter: ");
    scanf("%c", &end);

    for (row = 0; row < end - LET + 1; row++)
    {
        for (empty = row; empty < end - LET; empty++)
            printf(" ");

        for (start = LET; start <= LET + row; start++)
            printf("%c", start);

        for (start = LET + row - 1; start >= LET; start--)
            printf("%c", start);

        printf("\n");
    }

    return 0;
}
