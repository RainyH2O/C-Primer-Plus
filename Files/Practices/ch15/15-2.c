#include <stdio.h>
#include <stdlib.h>

int bstoi(const char *);
char * itobs(int, char *);

int main(int argc, char * argv[])
{
    int num1, num2;
    char num[8 * sizeof(int) + 1];

    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s string1 string2\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    num1 = bstoi(argv[1]);
    num2 = bstoi(argv[2]);
    printf("~%s: %s\n", argv[1], itobs(~num1, num));
    printf("~%s: %s\n", argv[2], itobs(~num2, num));
    printf("%s & %s: %s\n", argv[1], argv[2], itobs(num1 & num2, num));
    printf("%s | %s: %s\n", argv[1], argv[2], itobs(num1 | num2, num));
    printf("%s ^ %s: %s\n", argv[1], argv[2], itobs(num1 ^ num2, num));

    return 0;
}

int bstoi(const char * ps)
{
    int val = 0;

    while (*ps)
        val = 2 * val + (*ps++ - '0');

    return val;
}

char * itobs(int n, char * ps)
{
    int i;
    static int size = 8 * sizeof(int);

    for (i = size - 1; i >= 0; i--, n >>= 1)
        ps[i] = (01 & n) + '0';
    ps[size] = '\0';

    return ps;
}
