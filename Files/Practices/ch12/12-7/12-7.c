#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "diceroll.h"

int main(void)
{
    int sets, s;
    int dice, roll;
    int sides;

    srand((unsigned int) time(0));

    printf("Enter the number of sets; enter q to stop.\n");
    while (scanf("%d", &sets) == 1 && sets > 0)
    {
        printf("How many sides and how many dice?\n");
        scanf("%d %d", &sides, &dice);
        printf("Here are %d sets of %d %d-sided throws.\n", sets, dice, sides);
        for (s = 0; s < sets; s++)
        {
            roll = roll_n_dice(dice, sides);
                printf("%d ", roll);
            if (s % 15 == 14)
                putchar('\n');
        }
        if (s % 15 != 0)
            putchar('\n');
        printf("How many sets? Enter q to stop.\n");
    }

    return 0;
}
