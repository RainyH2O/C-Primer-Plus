#include <stdio.h>

int main(void)
{
    float gas,s;
    const float g2l = 3.785;
    const float m2k = 1.609;

    printf("Enter the number of distance and gas:");
    scanf("%f %f", &s, &gas);
    printf("%.1f\n", s / gas);
    printf("%.1f\n", 100 / ((s * m2k) / (gas * g2l)));

    return 0;
}
