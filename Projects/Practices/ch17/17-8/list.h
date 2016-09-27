/* list.h -- 简单列表类型的头文件 */
#ifndef LIST_H_
#define LIST_H_
#include <stdbool.h>    /* C99特性 */

/* 特定于程序的声明 */
#define TSIZE 20    /* 数组大小 */

/* 一般类型定义 */
typedef struct listitem
{
    char petname[TSIZE];
    char petkind[TSIZE];
} ListItem;

typedef struct listnode
{
    ListItem listitem;
    struct listnode * next;
} ListNode;

typedef ListNode * List;
/* 函数原型                                        */
/* 操作：初始化一个列表                            */
/* 操作前：plist指向一个列表                       */
/* 操作后：该列表被初始化为空列表                  */
void InitializeList(List * plist);

/* 操作：确定列表是否为空列表                      */
/* 操作前：plist指向一个已初始化的列表             */
/* 操作后：如果该列表为空则返回true；否则返回false */
bool ListIsEmpty(const List * plist);

/* 操作：确定列表是否已满                          */
/* 操作前：plist指向一个已初始化的列表             */
/* 操作后：如果该列表已满则返回true；否则返回false */
bool ListIsFull(const List * plist);

/* 操作：确定列表中项目的个数                      */
/* 操作前：plist指向一个已初始化的列表             */
/* 操作后：返回该列表中项目的个数                  */
unsigned int ListItemCount(const List * plist);

/* 操作：在列表尾部添加一个项目                    */
/* 操作前：item是要被增加到列表的项目              */
/*         plist指向一个已初始化的列表             */
/* 操作后：如果可能的话，在列表尾部添加一个新项目，*/
/*         函数返回true；否则函数返回false         */
bool AddListItem(ListItem item, List * plist);

/* 操作：把一个函数作用于列表中的每个项目          */
/* 操作前：plist指向一个已初始化的列表             */
/*         pfun指向一个函数，该函数接受            */
/*         一个Item参数并且无返回值                */
/* 操作后：pfun指向的函数被作用到                  */
/*         列表中的每个项目一次                    */
void TraverseList(const List * plist, void (* pfun)(ListItem item));

/* 操作：释放已分配的内存（如果有）                */
/* 操作前：plist指向一个已初始化的列表             */
/* 操作后：为该列表分配的内存已被释放              */
/*         并且该列表被置为空列表                  */
void EmptyTheList(List * plist);

int DeleteListNode(const ListItem * pi, List * plist);

#endif
