#include <stdio.h>

long Fibonacci(int);

int main(void)
{
    int index;

    printf("Please enter index number in the Fibonacci: ");
    while (scanf("%d", &index) == 1 )
    {
        printf("The number of %d in the Fibonacci is: %ld\n", index, Fibonacci(index));
        printf("Please enter next index number in the Fibonacci: ");
    }
    printf("Bye!\n");

    return 0;
}

long Fibonacci(int i)
{
    long num = 1, pnum = 1, temp;
    int j;

    if (i == 1 || i == 2)
        return num;
    else
    {
        for (j = 0; j < i - 2; j++)
        {
            temp = pnum;
            pnum = num;
            num += temp;
        }
        return num;
    }
}
