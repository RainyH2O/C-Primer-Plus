#include <stdio.h>

int critic(void);

int main(void)
{
    int units;

    printf("How many pound to a firkin of butter?\n");
    scanf("%d", &units);
    while (units != 56)
        units = critic();
    printf("You mast have looked it up!\n");

    return 0;
}

int critic(void)
{
    int units;

    printf("No luck, chummy. Try again.\n");
    scanf("%d", &units);

    return units;
}
