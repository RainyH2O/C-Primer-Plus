#include <stdio.h>

int main(void)
{
    int col, row, n;

    for (row = 0; row < 6; row++)
    {
        for (col = row + 1, n = 0; col > 0; col--, n++)
            printf("%c", 'F' - n);
        printf("\n");
    }

    return 0;
}
