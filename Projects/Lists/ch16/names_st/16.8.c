// useheader.c -- ʹ��names_st�ṹ
#include <stdio.h>
#include "names_st.h"
// ��ס����names_st.c�ļ�

int main(void)
{
    names candidate;

    get_names(&candidate);
    printf("Let's welcome ");
    show_names(&candidate);
    printf(" to this program!\n");

    return 0;
}
