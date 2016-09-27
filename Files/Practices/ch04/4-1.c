#include <stdio.h>

int main(void)
{
    char fname[10],lname[10];

    printf("Enter your first name and last name:");
    scanf("%s%s", fname, lname);
    printf("%s,%s\n", fname, lname);

    return 0;
}
