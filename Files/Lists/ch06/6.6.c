/* t_and_f.c -- C�е���ͼ� */
#include <stdio.h>
int main(void)
{
    int true_val, false_val;

    true_val = (10 > 2);        /* һ������ʽ��ֵ */
    false_val = (10 == 2);  /* һ���ٱ��ʽ��ֵ */
    printf("true = %d; false = %d \n", true_val, false_val);
    return 0;
}
