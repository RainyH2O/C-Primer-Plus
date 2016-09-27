#include <stdio.h>
#define LIM 10

void calltime(void);

static int times = 0;

int main(void)
{
    int i;

    for (i = 0; i < LIM; i++)
        calltime();
    printf("The function is called by %d times.\n", times);

    return 0;
}

void calltime(void)
{
    times++;
}
