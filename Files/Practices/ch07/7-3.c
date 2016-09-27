#include <stdio.h>

int main(void)
{
    int n;
    int e_ct = 0, o_ct = 0;
    double e_sum = 0.0, o_sum = 0.0;

    printf("Enter some integer numbers: ");
    while (scanf("%d", &n) == 1 && n != 0)
    {
        if (n % 2 == 0)
        {
            e_ct++;
            e_sum += n;
        }
        else
        {
            o_ct++;
            o_sum += n;
        }
    }
    if (e_ct > 0)
        printf("E: %d\nE Average: %.2f\n", e_ct, e_sum / e_ct);
    if (o_ct > 0)
        printf("O: %d\nO Average: %.2f\n", o_ct, o_sum / o_ct);
    printf("Done!\n");
    return 0;
}
