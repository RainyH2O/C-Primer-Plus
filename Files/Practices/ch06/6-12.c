#include <stdio.h>

int main(void)
{
    int num[8], i, val;

    for (i = 0, val = 1; i < 8; i++)
    {
        num[i] = val;
        val *= 2;
    }
    i = 0;
    do
    {
        printf("%d ", num[i]);
        i++;
    }while (i < 8);
    printf("\n");

    return 0;
}
