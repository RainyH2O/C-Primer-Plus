#include <stdio.h>

int main(void)
{
    char str[255];
    int i = 0;

    printf("Please enter a string: ");
    scanf("%c", &str[i]);
    while (str[i] != '\n')
    {
        i++;
        scanf("%c", &str[i]);
    }

    for(i--; i >= 0; i--)
        printf("%c", str[i]);
    printf("\n");

    return 0;
}
