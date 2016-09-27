#include <stdio.h>

int main(void)
{
    float height;
    char name[20];

    printf("Enter your height(cm) and name:");
    scanf("%f %s", &height, name);
    printf("%s, you are %0.3f meter tall\n", name, height / 100.0);

    return 0;
}
