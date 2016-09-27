#include <stdio.h>

int main(void)
{
    int n, i = 0;

    printf("Enter a number:");
    scanf("%d", &n);
    printf("Output:\n");
    while (i <= 10)
    {
        printf("%d\n", n);
        n++;
        i++;
    }

    return 0;
}
