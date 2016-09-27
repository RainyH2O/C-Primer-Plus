// file_eof.c -- ��һ���ļ�����ʾ������
#include <stdio.h>
#include <stdlib.h>             // Ϊ��ʹ��exit()
int main()
{
    int ch;
    FILE * fp;
    char fname[50];             // ���ڴ���ļ���

    printf("Enter the name of the file: ");
    scanf("%s", fname);
    fp = fopen(fname, "r");     // ���ļ��Թ���ȡ
    if (fp == NULL)             // ���Դ��ļ�ʧ��
    {
        printf("Failed to open file. Bye\n");
        exit(1);                // ��ֹ����
    }
    // getc(fp)�Ӵ򿪵��ļ��л�ȡһ���ַ�
    while ((ch = getc(fp)) != EOF)
        putchar(ch);
    fclose(fp);                 // �ر��ļ�
    return 0;
}
