#include <stdio.h>
int main(void)
{
    int age;
    float seconds;

    printf("Please enter your age:");
    scanf("%d",&age);
    seconds = age * 3.156e7f;
    printf("The seconds of your life is %fs\n",seconds);

    return 0;
}
