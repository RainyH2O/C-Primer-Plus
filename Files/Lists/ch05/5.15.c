/* pound.c -- �������һ�������ĺ���                  */
#include <stdio.h>
void pound(int n);  /* ANSI����ԭ��                 */
int main(void)
{
    int times = 5;
    char ch = '!';  /* ASCII��ֵΪ33                  */
    float f = 6.0;
    pound(times);   /* int����                        */
    pound(ch);      /* char�����Զ�ת��Ϊint����      */
    pound((int) f); /* ָ���������fǿ��ת��Ϊint���� */
    return 0;
}

void pound(int n)   /* ANSI���ĺ���ͷ               */
{                   /* ˵���ú�������һ��int����      */
    while (n-- > 0)
        printf("#");
    printf("\n");
}
