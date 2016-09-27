/* stack.h -- 栈类型的接口 */
#ifndef _STACK_H_
#define _STACK_H_
#include <stdbool.h>
/* 在这里插入项目类型 */
/* 例如：typedef int Item; */
typedef char Item;

#define MAXSTACK 100
typedef struct stack
{
    Item items[MAXSTACK];   /* 存放信息             */
    int top;                /* 第一个空位的索引     */
} Stack;

/* 操作：初始化栈                                   */
/* 操作前：ps指向一个栈                             */
/* 操作后：该栈被初始化为空栈                       */
void InitializeStack(Stack * ps);

/* 操作：检查栈是否已满                             */
/* 操作前：ps指向一个已初始化的栈                   */
/* 操作后：如果该栈已满，返回true；否则返回false    */
bool FullStack(const Stack * ps);

/* 操作：检查栈是否为空                             */
/* 操作前：ps指向一个已初始化的栈                   */
/* 操作后：如果该栈为空，返回true；否则返回false    */
bool EmptyStack(const Stack * ps);

/* 操作：把项目压入栈顶                             */
/* 操作前：ps指向一个已初始化的栈                   */
/*         item是要放到栈顶的项目                   */
/* 操作后：如果栈不为满，把item放到栈顶             */
/*         函数返回true；否则，                     */
/*         不改变栈，函数返回false                  */
bool Push(Item item, Stack * ps);

/* 操作：从栈顶删除项目                             */
/* 操作前：ps指向一个已初始化的栈                   */
/* 操作后：如果栈不为空，栈顶的项目                 */
/*         被复制到* pitem，并被从栈顶              */
/*         删除，函数返回true；如果                 */
/*         这一操作清空了栈，栈被重置为空           */
/*         如果栈开始时就为空，                     */
/*         不改变栈，函数返回false                  */
bool Pop(Item * pitem, Stack * ps);

#endif // _STACK_H_
