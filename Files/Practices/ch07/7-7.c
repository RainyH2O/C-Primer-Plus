#include <stdio.h>
#define BASE 10.00
#define TIME 40
#define TIMES 1.5
#define BREAK1 300
#define BREAK2 450
#define RATE1 0.15
#define RATE2 0.2
#define RATE3 0.25

int main(void)
{
    double time, sum, tax;

    printf("Enter the work time(hours) of a week: ");
    scanf("%lf", &time);

    if (time > TIME)
        time = TIME + (time - TIME) * TIMES;

    sum = time * BASE;
    printf("Sum: %f\n", sum);

    if (sum < BREAK1)
        tax = sum * RATE1;
    else if (sum >= BREAK1 && sum <= BREAK2)
        tax = BREAK1 * RATE1 + (sum - BREAK1) * RATE2;
    else
        tax = BREAK1 * RATE1 + (BREAK2 - BREAK1) * RATE2 + (sum - BREAK2) * RATE3;
    printf("Tax: %f\n", tax);
    printf("Pure: %f\n", sum - tax);

    return 0;
}
