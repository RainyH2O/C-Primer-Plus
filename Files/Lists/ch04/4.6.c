/* printout.c -- ʹ��ת��˵���� */
#include <stdio.h>
#define PI 3.141593
int main(void)
{
    int number = 5;
    float expresso = 13.5;
    int cost = 3100;
    printf("The %d CEOs drank %f cups of expresso.\n", number,
           expresso);
    printf("The value of pi is %f.\n", PI);
    printf("Farewell! thos art too dear for mu possessing,\n");
    printf("%c%d\n", '$', 2 * cost);
    return 0;
}
