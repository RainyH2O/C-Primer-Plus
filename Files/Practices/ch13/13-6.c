#include <stdio.h>
#include <stdlib.h>         // Ϊ�˵���exit()
#include <string.h>         // Ϊstrcpy()��strcat()�����ṩԭ��
#define LEN 40
int main(void)
{
    FILE *in, *out;         // ��������FILEָ��
    int ch;
    char file[LEN];
    char name[LEN];         // ���ڴ洢�����ļ���
    int count = 0;

    printf("Enter filename: ");
    gets(file);

// ʵ������
    if ((in = fopen(file, "r")) == NULL)
    {
        fprintf(stderr, "I couldn't open the file \"%s\"\n",
                file);
        exit(2);
    }

// ʵ�����
    strcpy(name, file);  // ���ļ������Ƶ�������
    strcat(name, ".red");   // ���ļ��������.red
    if ((out = fopen(name, "w")) == NULL)
    {                       // ���ļ��Թ�����
        fprintf(stderr, "Can't create output file.\n");
        exit(3);
    }

// ��������
    while ((ch = getc(in)) != EOF)
        if (count++ % 3 == 0)
            putc(ch, out);  // ��ӡÿ3���ַ��е�1��

// ��β����
    if (fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr, "Error in closing files\n");

    return 0;
}
