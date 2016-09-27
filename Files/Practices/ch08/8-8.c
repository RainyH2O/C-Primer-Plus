#include <stdio.h>
#

void menu(void);
void add(void);
void sub(void);
void mul(void);
void div(void);
float get_f(void);

int main(void)
{
    char ch;
    float n;

    menu();

    while ((ch = getchar()) != 'q')
    {
        if (ch == '\n')
            continue;
        while (getchar() != '\n')
            continue;
        switch (ch)
        {
            case 'a':
                add();
                break;
            case 's':
                sub();
                break;
            case 'm':
                mul();
                break;
            case 'd':
                div();
                break;
            default:
                printf("Enter is wrong, please enter a, s, m, d or q!\n");
                continue;
        }
        menu();
    }
    printf("Bye.\n");

    return 0;
}

void menu(void)
{
    printf("Enter the operation of your choice:\n");
    printf("a. add         s. subtract\n");
    printf("m. multiply     d. divide\n");
    printf("q. quit\n");
}

void add(void)
{
    float n1, n2;
    float n;

    printf("Enter first number: ");
    n1 = get_f();
    printf("Enter second number: ");
    n2 = get_f();
    n = n1 + n2;
    printf("%.1f + %.1f = %.1f\n", n1, n2, n);
}

void sub(void)
{
    float n1, n2;
    float n;

    printf("Enter first number: ");
    n1 = get_f();
    printf("Enter second number: ");
    n2 = get_f();
    n = n1 - n2;
    printf("%.1f - %.1f = %.1f\n", n1, n2, n);
}

void mul(void)
{
    float n1, n2;
    float n;

    printf("Enter first number: ");
    n1 = get_f();
    printf("Enter second number: ");
    n2 = get_f();
    n = n1 * n2;
    printf("%.1f * %.1f = %.1f\n", n1, n2, n);
}

void div(void)
{
    float n1, n2;
    float n;

    printf("Enter first number: ");
    n1 = get_f();
    printf("Enter second number: ");
    n2 = get_f();
    while (n2 == 0)
    {
        printf("Enter a number other than 0: ");
        n2 = get_f();
    }
    n = n1 / n2;
    printf("%.1f / %.1f = %.1f\n", n1, n2, n);
}

float get_f(void)
{
    float num;
    char ch;

    while (scanf("%f", &num) != 1)
    {
        while ((ch = getchar()) != '\n')
            putchar(ch);
        printf(" is not an number.\n");
        printf("Please enter a number, such as 2.5, -1.78E8, or 3: ");
    }

    return num;
}
