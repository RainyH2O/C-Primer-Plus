/* loccheck.c -- �鿴�����Ĵ洢��ַ */
#include <stdio.h>
void mikado(int);                   /* ��������     */
int main(void)
{
    int pooh = 2, bah = 5;          /* main()�����еľֲ����� */

    printf("In main(), pooh = %d and &pooh = %p\n",
           pooh, &pooh);
    printf("In main(), bah = %d and &bah = %p\n",
           bah, &bah);
    mikado(pooh);
    return 0;
}
void mikado(int bah)                /* ���庯�� */
{
    int pooh = 10;                  /* mikdo()�����еľֲ����� */

    printf("In mikado(), pooh = %d and &pooh = %p\n",
           pooh, &pooh);
    printf("In mikado(), bah = %d and &bah = %p\n",
           bah, &bah);
}
