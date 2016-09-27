#include <stdio.h>
#define I_PER_C 2.54
#define F_PER_I 12.0

int main(void)
{
    float cm, inch;
    int foot;

    printf("Enter a height in centimeters: ");
    scanf("%f", &cm);
    while (cm > 0)
    {
        inch = cm / I_PER_C;
        foot =  inch / F_PER_I;
        printf("%.1f cm = %d feet, %.1f inches\n", cm, foot, inch);
        printf("Enter a height in centimeters (<=0 to quit): ");
        scanf("%f", &cm);
    }
    printf("bye\n");

    return 0;
}
