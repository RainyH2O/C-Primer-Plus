#include <stdio.h>

int onbits(int);

int main(void)
{
    int num;
    int bit_num;

    printf("Enter a number: ");
    scanf("%d", &num);
    printf("There are %d bits are on in %d\n", onbits(num), num);

    return 0;
}

int onbits(int n)
{
    static int size = 8 * sizeof(int);
    int i;
    int count = 0;

    for (i = size - 1; i >= 0; i--, n >>= 1)
        if ((01 & n) == 01)
            count++;

    return count;
}
