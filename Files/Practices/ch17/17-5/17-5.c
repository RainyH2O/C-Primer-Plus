#include <stdio.h>
#include "stack.h"
int main(void)
{
    Stack stch;
    Item str[MAXSTACK];
    Item temp;
    int i;

    InitializeStack(&stch);

    printf("Please enter a string: ");
    while (gets(str) != NULL && str[0] != '\0')
    {
        printf("Original string: ");
        puts(str);
        for (i = 0; str[i] != '\0' && !FullStack(&stch); i++)
            Push(str[i], &stch);
        printf("Reversed string: ");
        while (!EmptyStack(&stch))
        {
            Pop(&temp, &stch);
            putchar(temp);
        }
        putchar('\n');
        printf("Please Enter next string: ");
    }
    puts("Done!");

    return 0;
}
