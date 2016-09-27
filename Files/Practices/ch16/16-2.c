#include <stdio.h>
#define ANUM(X,Y) (1.0 / ((1.0 / (X) + 1.0 / (Y)) / 2.0))

int main(void)
{
    float x, y;

    printf("Enter two number: ");
    scanf("%f %f", &x, &y);
    printf("The average of %f and %f is: %f\n", x, y, ANUM(x, y));

    return 0;
}
