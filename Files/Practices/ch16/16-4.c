#include <stdio.h>
#include <time.h>

void clocktime(double);

int main(void)
{
    double t;

    printf("Enter a time: ");
    scanf("%lf", &t);
    clocktime(t);

    return 0;
}

void clocktime(double t)
{
    double start;

    start = (double) clock() / CLOCKS_PER_SEC;
    while ((double) clock() / CLOCKS_PER_SEC < start + t)
        continue;
    printf("Over!\n");

    return;
}
