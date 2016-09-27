#include <stdio.h>

int main(void)
{
    int l_limit, u_limit, i;

    printf("This is a square and cube table of a num.\n");
    printf("Please enter the lower limit and upper limit of the table: ");
    scanf("%d %d", &l_limit, &u_limit);

    printf("  Num      Squar      Cube       \n");
    for (i = l_limit; i <= u_limit; i++)
        printf("%5d%11d%10d\n", i, i * i, i * i * i);

    return 0;
}
