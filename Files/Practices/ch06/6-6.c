#include <stdio.h>
#include <string.h>
#define SIZE 30

int main(void)
{
    char a[SIZE];
    int i;

    printf("Enter a word: ");
    scanf("%s", a);

    for(i = strlen(a) - 1; i >= 0; i--)
        printf("%c", a[i]);
    printf("\n");

    return 0;
}
