#include <stdio.h>
#include "stack.h"

/* 接口函数 */

/* 把栈设置为空栈 */
void InitializeStack(Stack * ps)
{
    ps->top = 0;
}

/* 检查栈已满则返回真 */
bool FullStack(const Stack * ps)
{
    if (ps->top == MAXSTACK)
        return true;
    else
        return false;
}

/* 检查栈为空则返回真 */
bool EmptyStack(const Stack * ps)
{
    if (ps->top == 0)
        return true;
    else
        return false;
}

/* 入栈 */
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

/* 出栈 */
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
