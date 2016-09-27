#include <stdio.h>

int main(void)
{
    int times;
    float sum, i, sign;

    printf("Enter the times: ");


    while (scanf("%d", &times) == 1)
    {
        for (sum = 0, i = 1.0; i <= times; i++)
            sum += 1.0 / i;
        printf("Sum is: %f\n", sum);

        for (sum = 0, i = 1.0, sign = -1.0; i <= times; i++)
        {
            sign *= -1.0;
            sum += sign * (1.0 / i);
        }
        printf("Sum is: %f\n", sum);
        printf("Enter next times: ");
    }

    return 0;
}
