#include <stdio.h>

int main(void)
{
    float water,num;

    printf("Enter the weight of water:");
    scanf("%f",&water);
    num = water * 950 / 3e-23f;
    printf("The number of water molecule is: %e\n",num);

    return 0;
}
