/* tree.h -- ����������          */
/* ���в���������ͬ����Ŀ        */
#ifndef _TREE_H_
#define _TREE_H_
#include <stdbool.h>

/* �����԰�Item���¶���Ϊ���ʵ����� */
typedef struct treeitem
{
    List petinfo;
    int count;
} TreeItem;

#define MAXITEMS 10

typedef struct treenode
{
    TreeItem treeitem;
    struct treenode * left;     /* ָ�����֧��ָ��     */
    struct treenode * right;    /* ָ����֧��ָ��       */
} TreeNode;

typedef struct tree
{
    TreeNode * root;            /* ָ��������ָ��       */
    int size;               /* ������Ŀ�ĸ���       */
} Tree;
/* ����ԭ��                                         */
/* ��������һ������ʼ��Ϊ����                       */
/* ����ǰ��ptreeָ��һ����                          */
/* �����󣺸����ѱ���ʼ��Ϊ����                     */
void InitializeTree(Tree * ptree);

/* ������ȷ�����Ƿ�Ϊ��                             */
/* ����ǰ��ptreeָ��һ����                          */
/* �����������Ϊ����������true�����򷵻�false  */
bool TreeIsEmpty(const Tree * ptree);

/* ������ȷ�����Ƿ�����                             */
/* ����ǰ��ptreeָ��һ����                          */
/* �����������������������true�����򷵻�false  */
bool TreeIsFull(const Tree * ptree);

/* ������ȷ��������Ŀ�ĸ���                         */
/* ����ǰ��ptreeָ��һ����                          */
/* �����󣺺�������������Ŀ�ĸ���                   */
int TreeItemCount(const Tree * ptree);

/* ���������������һ����Ŀ                         */
/* ����ǰ��pi�Ǵ���ӵ���Ŀ�ĵ�ַ                   */
/*         ptreeָ��һ���Ѿ���ʼ������              */
/* ������������ܣ������Ѹ���Ŀ                   */
/*         ��ӵ����в�����true��                   */
/*         ����������false                        */
bool AddTreeItem(ListItem pi, Tree * ptree);

/* �����������в���һ����Ŀ                         */
/* ����ǰ��piָ��һ����Ŀ                           */
/*         ptreeָ��һ���Ѿ���ʼ������              */
/* �������������Ŀ�����У���������true��       */
/*         ���򷵻�false                            */
bool InTree(const TreeItem * pi, const Tree * ptree);

/* ������������ɾ��һ����Ŀ                         */
/* ����ǰ��pi�Ǵ�ɾ������Ŀ�ĵ�ַ                   */
/*         ptreeָ��һ���Ѿ���ʼ������              */
/* ������������ܣ�����������ɾ������Ŀ           */
/*         ������true������������false            */
bool DeleteTreeItem(const ListItem * pi, Tree * ptree);

/* ��������һ����������������ÿһ����Ŀ             */
/* ����ǰ��ptreeָ��һ����                          */
/*         pfunָ��һ��û�з���ֵ�ĺ���             */
/*         �ú�������һ��ListItem��Ϊ����           */
/* ������pfunָ��ĺ�����������                   */
/*         ����ÿ����Ŀһ��                         */
void TraverseTree(const Tree * ptree, void (* pfun)(ListItem treeitem));

/* ������������ɾ�����нڵ�                         */
/* ����ǰ��ptreeָ��һ���Ѿ���ʼ������              */
/* �����󣺸���Ϊ����                               */
void DeleteAll(Tree * ptree);

/* ������ȷ������ÿ���б���Ŀ�ĸ���                 */
/* ����ǰ��ptreeָ��һ����                          */
/* �����󣺺�����������ÿ���б���Ŀ�ĸ���           */
int TreeListItemCount(const Tree * ptree);

TreeNode * WhereInTree(const ListItem * pi, const Tree * ptree);

bool DeleteListItem(const ListItem * pi, Tree * ptree);

#endif
