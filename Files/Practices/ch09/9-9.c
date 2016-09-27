#include <stdio.h>

void to_base_n(unsigned long n, int i);

int main(void)
{
    unsigned long number;
    int i, t;

    printf("Enter an integer (q to quit):\n");
    while (t = scanf("%ul", &number) == 1)
    {
        printf("Enter a system in number: ");
        scanf("%d", &i);
        printf("Equivalent: ");
        to_base_n(number, i);
        putchar('\n');
        printf("Enter an integer (q to quit):\n");
    }
    printf("Done.\n");

    return 0;
}

void to_base_n(unsigned long n, int i)
{
    int r;

    r = n % i;
    if (n >= i)
        to_base_n(n / i, i);
    putchar('0' + r);

    return;
}
