#include <stdio.h>

int main(void)
{
    int num[8];
    int i;

    printf("Enter 8 numbers: ");
    for (i = 0; i < 8; i++)
        scanf("%d", &num[i]);
    printf("The 8 numbers are: ");
    for (i = 7; i >= 0; i--)
        printf("%d ", num[i]);
    printf("\n");

    return 0;
}
