// cypher2.c -- �ı����룬ֻ��������ĸ�ַ�
#include <stdio.h>
#include <ctype.h>              // Ϊisalpha()�ṩԭ��
int main(void)
{
    char ch;

    while ((ch = getchar()) != '\n')
    {
        if (isalpha(ch))        // �����һ����ĸ
            putchar(ch + 1);    // ��ı���
        else                    // ����
            putchar(ch);        // ԭ����ӡ��
    }
    putchar(ch);                // ��ӡ�����ַ�
    return 0;
}
