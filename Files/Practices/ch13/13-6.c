#include <stdio.h>
#include <stdlib.h>         // 为了调用exit()
#include <string.h>         // 为strcpy()和strcat()函数提供原型
#define LEN 40
int main(void)
{
    FILE *in, *out;         // 声明两个FILE指针
    int ch;
    char file[LEN];
    char name[LEN];         // 用于存储输入文件名
    int count = 0;

    printf("Enter filename: ");
    gets(file);

// 实现输入
    if ((in = fopen(file, "r")) == NULL)
    {
        fprintf(stderr, "I couldn't open the file \"%s\"\n",
                file);
        exit(2);
    }

// 实现输出
    strcpy(name, file);  // 把文件名复制到数组中
    strcat(name, ".red");   // 在文件名后添加.red
    if ((out = fopen(name, "w")) == NULL)
    {                       // 打开文件以供输入
        fprintf(stderr, "Can't create output file.\n");
        exit(3);
    }

// 复制数据
    while ((ch = getc(in)) != EOF)
        if (count++ % 3 == 0)
            putc(ch, out);  // 打印每3个字符中的1个

// 收尾工作
    if (fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr, "Error in closing files\n");

    return 0;
}
