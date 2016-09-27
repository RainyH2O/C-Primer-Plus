#include <stdio.h>
#define PRICE1 1.25
#define PRICE2 0.65
#define PRICE3 0.89
#define DISCOUNT 0.05
#define FREIGHT1 3.50
#define FREIGHT2 19.00
#define FREIGHT3 8.00

int main(void)
{
    char item;
    double price;
    double a_pound = 0;
    double b_pound = 0;
    double c_pound = 0;
    double a_sum;
    double b_sum;
    double c_sum;
    double pound;
    double sum;
    double discount;
    double freight;
    double allsum;

    printf("****ABC Mail Order Grocery****\n");
    printf("Choose a vegetable(q to quit):\n");
    printf("a. artichokes                 \n");
    printf("b. beets                      \n");
    printf("c. carrots                    \n");
    printf("******************************\n");

    //while (scanf("%c", &itme) == 1 && itme != 'q')
    while ((item = getchar()) != 'q')
    {
        if (item != '\n')
            continue;
        switch (item)
        {
            case 'a':
                printf("Enter the pounds of artichokes: ");
                scanf("%lf", &a_pound);
                break;
            case 'b':
                printf("Enter the pounds of beets: ");
                scanf("%lf", &b_pound);
                break;
            case 'c':
                printf("Enter the pounds of carrots: ");
                scanf("%lf", &c_pound);
                break;
            default:
                printf("Enter wrong! Please enter a-c.\n");
                break;
        }
        printf("Choose another vegetable.\n");
    }

    a_sum = a_pound * PRICE1;
    b_sum = b_pound * PRICE2;
    c_sum = c_pound * PRICE3;
    sum = a_sum + b_sum + c_sum;
    pound = a_pound + b_pound + c_pound;
    if (sum >= 100)
        discount = sum * DISCOUNT;
    else
        discount = 0;
    if (pound == 0)
        freight = 0;
    else if (pound <= 5)
        freight = FREIGHT1;
    else if (pound <= 20 && pound > 5)
        freight = FREIGHT2;
    else
        freight = FREIGHT3 + pound * 0.1;

    allsum = sum + freight - discount;

    printf("Artichokes:\n");
    printf("Pounds: %f\n", a_pound);
    printf("Price: $%f/p\n", PRICE1);
    printf("COST: $%f\n\n", a_sum);
    printf("Beets:\n");
    printf("Pounds: %f\n", b_pound);
    printf("Price: $%f/p\n", PRICE2);
    printf("COST: $%f\n\n", b_sum);
    printf("Carrots:\n");
    printf("Pounds: %f\n", c_pound);
    printf("Price: $%f/p\n", PRICE3);
    printf("COST: $%f\n\n", c_sum);

    printf("Order Sum: $%f\n", sum);
    printf("Discount: $%f\n", discount);
    if (freight != 0)
        printf("Freight: $%f\n", freight);

    printf("ALL cost: $%f\n", allsum);

    return 0;
}
