#include <stdio.h>
#include "stack.h"

/* �ӿں��� */

/* ��ջ����Ϊ��ջ */
void InitializeStack(Stack * ps)
{
    ps->top = 0;
}

/* ���ջ�����򷵻��� */
bool FullStack(const Stack * ps)
{
    if (ps->top == MAXSTACK)
        return true;
    else
        return false;
}

/* ���ջΪ���򷵻��� */
bool EmptyStack(const Stack * ps)
{
    if (ps->top == 0)
        return true;
    else
        return false;
}

/* ��ջ */
bool Push(Item item, Stack * ps)
{
    if (!FullStack(ps))
    {
        ps->items[ps->top++] = item;
        return true;
    }
    else
        return false;
}

/* ��ջ */
bool Pop(Item * pitem, Stack * ps)
{
    if (!EmptyStack(ps))
    {
        *pitem = ps->items[--ps->top];
        if (EmptyStack(ps))
            InitializeStack(ps);
        return true;
    }
    else
        return false;
}
