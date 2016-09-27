#include <stdio.h>
int main(void)
{
    char ch;
    int guess = 50;
    int start = 1;
    int end = 100;
    printf("Pick an integer from 1 to 100. I will try to guess ");
    printf("it.\nRespond with a y if my guess is right, with");
    printf("\nan n if it is wrong, with\na m if it is ");
    printf("more than your integer and with\nan l if it is less ");
    printf("then your integer.\n");
    printf("Uh...is your number %d or more than it or less than it?\n", guess);
    while ((ch = getchar()) != 'y')  /*获取用户响应并和y比较*/
    {
        if (ch == '\n')
            continue;
        switch (ch)
        {
            case 'm':
                end = guess;
                break;
            case 'l':
                start = guess;
                break;
            default:
                printf("Your input is wrong! Please use y or m or n.\n");
                continue;
        }
        guess = (start + end) / 2;
        printf("Well, then, is it %d or more than it or less than it?\n", guess);
    }
    printf("I knew I could do it!\n");

    return 0;
}
