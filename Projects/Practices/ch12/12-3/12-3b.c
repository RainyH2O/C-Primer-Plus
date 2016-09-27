#include <stdio.h>
#include "pe12-3a.h"

int main(void)
{
    int mode;
    double distance, fuel;

    printf("Enter 0 for metric mode, 1 for US mode: ");
    scanf("%d", &mode);
    while (mode >= 0)
    {
        set_mode(&mode);
        get_info(&distance, &fuel, mode);
        show_info(distance, fuel, mode);
        printf("Enter 0 for metric mode, 1 for US mode:");
        printf(" (-1 to quit): ");
        scanf("%d", &mode);
    }
    printf("Done.\n");

    return 0;
}
