#include <stdio.h>
#include <stdlib.h> // ANSI C��exit()ԭ��

int main(void)
{
    int ch;         // ��ȡʱ�洢ÿ���ַ���λ��
    FILE *fp;       // �ļ�ָ��
    long count = 0;
    char name[30];

    printf("Enter filename: ");
    gets(name);
    if ((fp = fopen(name, "r")) == NULL)
    {
        printf("Can't open %s\n", name);
        exit(1);
    }
    while ((ch = getc(fp)) != EOF)
    {
        putc(ch, stdout);   // �൱��putchar(ch);
        count++;
    }
    fclose(fp);
    printf("File %s has %ld characters\n", name, count);

    return 0;
}
