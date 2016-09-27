#include <stdio.h>
#include <ctype.h>

int atoi(char *);

int main(void)
{
    char str[] = "1234567890";

    printf("The number of %s is %d.\n", str, atoi(str));

    return 0;
}

int atoi(char *str)
{
    int i;
    int num;

    for (num = 0; isdigit(*str); str++)
         num = num * 10 + (*str - '0');

    return num;
}
