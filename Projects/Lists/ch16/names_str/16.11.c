// doubincl.c -- ���ΰ���ͬһͷ�ļ�
#include <stdio.h>
#include "names_st.h"
#include "names_st.h"   // ��С�����ΰ���ͬһͷ�ļ�

int main()
{
    names winner = {"Less", "Ismoor"};
    printf("The winner is %s %s.\n", winner.first,
           winner.last);
    return 0;
}
