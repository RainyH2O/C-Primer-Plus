#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int num, div, limit;
    bool isPrime;

    printf("Enter a number to limit the prime number(q to quit):\n");
    while (scanf("%d", &limit) == 1)
    {
        for (num = 2; num <= limit; num++)
        {
            for (div = 2, isPrime = true; (div * div) <= num && isPrime != false; div++)
                if (num % div == 0)
                    isPrime = false;
            if (isPrime)
                printf("%d ", num);
        }
        printf("\n");
    }
    printf("Done!\n");

    return 0;
}
