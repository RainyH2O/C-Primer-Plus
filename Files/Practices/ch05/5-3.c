#include <stdio.h>
#define W_PER_D 7

int main(void)
{
    int d, weeks, days;

    printf("Enter the number of days(0 to quit): ");
    scanf("%d", &d);
    while (d > 0)
    {
        weeks = d / W_PER_D;
        days = d % W_PER_D;
        printf("%d days are %d weeks, %d days.\n", d, weeks, days);
        printf("Enter next number of days(0 to quit): ");
        scanf("%d", &d);
    }
    printf("Done!\n");

    return 0;
}
