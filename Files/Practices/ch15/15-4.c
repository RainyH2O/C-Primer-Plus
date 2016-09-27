#include <stdio.h>

int checkbit(int, int);

int main(void)
{
    int num, pos;

    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Enter a position: ");
    scanf("%d", &pos);
    printf("The bit are: %s\n", checkbit(num, pos)? "On": "Off");

    return 0;
}

int checkbit(int n, int p)
{
    int stat = 0;

    if ((01 & (n >> p)) == 01)
        stat = 1;

    return stat;
}
