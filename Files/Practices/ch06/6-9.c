#include <stdio.h>

int main(void)
{
    int lower, upper, sum, n;

    printf("Enter lower and upper integer limits: ");
    scanf("%d %d", &lower, &upper);

    while (lower < upper)
    {
        sum = 0;
        for (n = lower; n <= upper; n++)
            sum += n * n;
        printf("The sums of the squares from %d to %d is %d\n", lower * lower, upper * upper, sum);
        printf("Enter next set of limits: ");
        scanf("%d %d", &lower, &upper);
    }
    printf("Done\n");

    return 0;
}
