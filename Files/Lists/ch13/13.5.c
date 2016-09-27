/* reverse.c -- ������ʾһ���ļ� */
#include <stdio.h>
#include <stdlib.h>
#define CNTL_Z '\032'   /* DOS�ı��ļ��е��ļ���β��� */
#define SLEN 50
int main(void)
{
    char file[SLEN];
    char ch;
    FILE *fp;
    long count, last;

    puts("Enter the name of the file to be processed: ");
    gets(file);
    if ((fp = fopen(file, "rb")) == NULL)
    {                                   /* ֻ���Ͷ�����ģʽ     */
        printf("reverse can't open %s\n", file);
        exit(1);
    }
    fseek(fp, 0L, SEEK_END);            /* ��λ���ļ���β��     */
    last = ftell(fp);
    for (count = 1L; count <= last; count++)
    {
        fseek(fp, -count, SEEK_END);    /* ����                 */
        ch = getc(fp);
    /* ���DOS����UNIX��Ҳ�ɹ��� */
        if (ch != CNTL_Z && ch != '\r')
            putchar(ch);
    /* ���Macintosh             */
    /*  if (ch == '\r')
            putchar('\n');
        else
            putchar(ch);         */
    }
        putchar('\n');
        fclose(fp);
        return 0;
}
