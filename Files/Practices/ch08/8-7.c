#include <stdio.h>
#define BASE1 8.75
#define BASE2 9.33
#define BASE3 10.00
#define BASE4 11.20
#define TIME 40
#define TIMES 1.5
#define BREAK1 300
#define BREAK2 450
#define RATE1 0.15
#define RATE2 0.2
#define RATE3 0.25

int main(void)
{
    char ch;
    double base, time, sum, tax;

    printf("*****************************************************************\n");
    printf("Enter the number corresponding to the desired pay rate or action:\n");
    printf("a. $8.75/hr                     b. $9.33                         \n");
    printf("c. $10.00/hr                    d. $11.20/hr                     \n");
    printf("q. quit                                                          \n");
    printf("*****************************************************************\n");

    while ((ch = getchar()) != 'q')
    {
        if (ch == '\n')
            continue;
        switch (ch)
        {
            case 'a':
                base = BASE1;
                break;
            case 'b':
                base = BASE2;
                break;
            case 'c':
                base = BASE3;
                break;
            case 'd':
                base = BASE4;
                break;
            default:
                printf("Worry! Please enter a-d or q to quit!\n");
                break;
        }
        if (ch >= 'a' && ch <= 'd' || ch == 'q')
        {
            printf("Enter the work time(hours) of a week: ");
            scanf("%lf", &time);

            if (time > TIME)
                time = TIME + (time - TIME) * TIMES;

            sum = time * base;
            printf("Sum: %f\n", sum);

            if (sum < BREAK1)
                tax = sum * RATE1;
            else if (sum >= BREAK1 && sum <= BREAK2)
                tax = BREAK1 * RATE1 + (sum - BREAK1) * RATE2;
            else
                tax = BREAK1 * RATE1 + (BREAK2 - BREAK1) * RATE2 + (sum - BREAK2) * RATE3;
            printf("Tax: %f\n", tax);
            printf("Pure: %f\n", sum - tax);
        }
        while (getchar() != '\n')
            continue;
    }

    return 0;
}
