// input.c -- ʲô�����ʹ��&
#include <stdio.h>
int main(void)
{
    int age;            //����
    float assets;       //����
    char pet[30];       //�ַ���

    printf("Enter your age, assets, and favorite pet.\n");
    scanf("%d %f", &age, &assets);  //�˴���Ҫʹ��&
    scanf("%s", pet);               //��char���鲻��ʹ��&
    printf("%d $%.2f %s\n", age, assets, pet);
    return 0;
}
