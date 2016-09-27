#include <stdio.h>
#include <string.h>

int bstoi(const char *);

int main(void)
{
    char * pbin = "01001001";

    printf("The num of %s is: %d\n", pbin, bstoi(pbin));

    return 0;
}

int bstoi(const char * str)
{
    int num, temp;
    int i, n;

    for (num = 0, n = strlen(str) - 1; *str; n--, str++)
    {
        temp = *str - '0';
        for (i = 0; i < n; i++)
            temp *= 2;
        num += temp;
    }

    return num;
}
