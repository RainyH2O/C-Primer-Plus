#include <stdio.h>

char * itobs(int , char *);
unsigned int rotate_l(unsigned int, int);

int main(void)
{
    unsigned int num;
    int p;
    char bin_str[8 * sizeof(unsigned int) + 1];

    printf("Enter a number: ");
    scanf("%u", &num);
    printf("Enter the number of rotate: ");
    scanf("%u", &p);
    printf("Orignal binary of %u: %s\n", num, itobs(num, bin_str));
    num = rotate_l(num, p);
    printf("Modified binary of %u: %s\n", num, itobs(num, bin_str));

    return 0;
}

unsigned int rotate_l(unsigned int n, int p)
{
    int mask = 1;
    int i;
    static int size = 8 * sizeof(unsigned int);

    mask <<= size - 1;
    for (i = 0; i < p; i++)
        if ((n & mask) == mask)
        {
            n <<= 1;
            n |= 1;
        }
        else
        {
            n <<= 1;
            n &= ~1;
        }

    return n;
}

char * itobs(int n, char * ps)
{
    int i;
    static int size = 8 * sizeof(unsigned int);

    for (i = size - 1; i >= 0; i--, n >>= 1)
        ps[i] = (01 & n) + '0';
    ps[size] = '\0';

    return ps;
}
