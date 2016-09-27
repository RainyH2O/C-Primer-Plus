#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000

int main(void)
{
    int i;
    unsigned seed;
    int num[SIZE];
    int times[10];

    printf("Enter seed: ");
    while (scanf("%d", &seed) == 1)
    {
        srand(seed);
        for (i = 0; i < 10; i++)
            times[i] = 0;
        for (i = 0; i < SIZE; i++)
            num[i] = rand() % 10 + 1;
        for (i = 0; i < SIZE; i++)
            switch (num[i])
            {
                case 1:
                    times[0]++;
                    break;
                case 2:
                    times[1]++;
                    break;
                case 3:
                    times[2]++;
                    break;
                case 4:
                    times[3]++;
                    break;
                case 5:
                    times[4]++;
                    break;
                case 6:
                    times[5]++;
                    break;
                case 7:
                    times[6]++;
                    break;
                case 8:
                    times[7]++;
                    break;
                case 9:
                    times[8]++;
                    break;
                case 10:
                    times[9]++;
                    break;
            }
        for (i = 0; i < 10; i++)
            printf("%d: %d\n", i + 1, times[i]);
        printf("Enter next seed: ");
    }

    return 0;
}
