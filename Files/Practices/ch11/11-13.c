#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    double num;
    double pow = 1;
    int n;
    int i;

    if (argc < 3 || (n = atoi(argv[2])) < 0)
        printf("Wrong!");
    else
    {
        if (n == 0)
            num = 1;
        else
        {
            num = atof(argv[1]);
            for (i = 0; i < n; i++)
                pow *= num;
        }
            printf("%f\n", pow);
    }

    return 0;
}
