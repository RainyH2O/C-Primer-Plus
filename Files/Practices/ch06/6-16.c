#include <stdio.h>

int main(void)
{
    double money = 100.0;
    int years = 0;

    while (money > 0)
    {
        money *= 1 + 0.08;
        money -= 10;
        years++;
    }
    printf("After %d years, Chuckie will clean his account!\n", years);

    return 0;
}
