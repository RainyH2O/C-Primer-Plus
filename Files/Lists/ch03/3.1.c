/* rhodium.c -- �ý���������������� */
#include <stdio.h>
int main(void)
{
    float weight;   /*�û������� */
    float value;    /*�����������ļ�ֵ */
    printf("Are you worth your weight in rhodium?\n");
    printf("Let's check it out.\n");
    printf("Please enter your weight in pounds:");
/*���û�����ȡ���� */
    scanf("%f",&weight);
/* ������Ϊÿ��˾770��Ԫ */
/* 14.5833�ѳ����Ƶ�Ӣ��ת��Ϊ����Ƶİ�˾ */
    value = 770 * weight * 14.5833;
    printf("Your weight in rhodium is worth $%.2f.\n", value);
    printf("You are easily worth that! If rhodium prices drop,\n");
    printf("eat more to maintain your value.\n");
    return 0;
}
