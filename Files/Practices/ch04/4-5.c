#include <stdio.h>
#include <string.h>

int main(void)
{
    char fname[10],lname[10];
    int n1,n2;

    printf("Enter your first name:");
    scanf("%s", fname);
    printf("Enter your last name:");
    scanf("%s", lname);
    n1 = strlen(fname);
    n2 = strlen(lname);
    printf("%s %s\n", fname, lname);
    printf("%*d %*d\n", n1, n1, n2, n2);
    printf("%s %s\n", fname ,lname);
    printf("%*-d %*-d\n", n1, n1, n2, n2);

    return 0;
}
