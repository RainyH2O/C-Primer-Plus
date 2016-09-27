#include <stdio.h>

int main(void)
{
    int col, row;

    for (row = 0; row < 5; row++)
    {
        for (col = row + 1; col > 0; col--)
            printf("$");
        printf("\n");
    }
    return 0;
}
