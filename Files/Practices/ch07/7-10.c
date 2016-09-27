#include <stdio.h>
#define BASE1 17850
#define BASE2 23900
#define BASE3 29750
#define BASE4 14875
#define RATE1 0.15
#define RATE2 0.28

int main(void)
{
    int n;
    double base;
    double gross;
    double taxes;

    printf("**********************************\n");
    printf("Choose your taxes type(q to quit):\n");
    printf("1、Single                         \n");
    printf("2、Head of Household              \n");
    printf("3、Married, Joint                 \n");
    printf("4、Married, Separate              \n");
    printf("**********************************\n");

    while (scanf("%d", &n) == 1)
    {
        switch (n)
        {
            case 1:
                base = BASE1;
                break;
            case 2:
                base = BASE2;
                break;
            case 3:
                base = BASE3;
                break;
            case 4:
                base = BASE4;
                break;
            default:
                printf("Please enter a number between 1 and 4:\n");
                break;
        }
        if (n >= 1 && n <= 4)
        {
            printf("Enter your gross:\n");
            scanf("%lf", &gross);
            if (gross > base)
                taxes = base * RATE1 + (gross - base) * RATE2;
            else
                taxes = gross * RATE1;

            printf("Your taxes: %.2f\n\n", taxes);
            printf("Enter another type:\n");
        }
    }
    printf("Done!\n");

    return 0;
}
