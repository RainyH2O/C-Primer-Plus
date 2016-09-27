#include <stdio.h>

int main(void)
{
    float inchhigh,cmhigh;

    printf("Enter your high in inch:");
    scanf("%f", &inchhigh);
    cmhigh = inchhigh * 2.54f;
    printf("Your high in cm is: %f\n", cmhigh);

    return 0;
}
