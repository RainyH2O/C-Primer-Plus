#include <stdio.h>

int main(void)
{
    int n;
    int r;
    int e_ct = 0;
    int o_ct = 0;
    double e_sum = 0.0;
    double o_sum = 0.0;

    printf("Enter integer numbers: ");
    while (scanf("%d", &n)== 1 && n != 0)
    {
        r = n % 2;
        switch (r)
        {
            case 0 :
                e_sum += n;
                e_ct++;
                break;
            case 1 :
                o_sum += n;
                o_ct++;
                break;
        }
    }
    if (e_ct > 0)
        printf("E: %d\nE Average: %.2f\n", e_ct, e_sum / e_ct);
    if (o_ct > 0)
        printf("O: %d\nO average: %.2f\n", o_ct, o_sum / o_ct);
    printf("Done!\n");

    return 0;
}
