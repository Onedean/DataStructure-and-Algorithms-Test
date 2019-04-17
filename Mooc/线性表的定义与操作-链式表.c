#include <stdio.h>
#include <stdbool.h>

typedef int ElementType;
typedef struct Lnode *List;
typedef struct Lnode *Position;

struct Lnode
{
    ElementType data;
    List next;
};

// 查找值：在链表l中查找值x的位置
struct Lnode *find(List l, ElementType x)
{
    Position p = l; // 指向头结点
    while (p && p->data != x)
    {                // 判断查找到或查找到表尾
        p = p->next; // p指向当前结点的下一个结点
    }
    return p ? p : NULL;
}

// 结点的插入:在链表l的位置p之前插入值x
bool insert(List l, ElementType x, Position p)
{
    Position pre = l; // 默认l有头结点，否则插入到表头会出现错误
    // 查找p之前的一个结点位置
    while (pre && pre->next != p)
    {
        pre = pre->next;
    }
    if (pre == NULL)
    {
        printf("插入位置参数错误\n");
        return false;
    }
    else
    {
        List temp = (List)malloc(sizeof(struct Lnode)); // 申请插入结点空间
        temp->data = x;                                 // 插入结点赋值
        temp->next = p;                                 // 插入结点指向下一个p位置
        pre->next = temp;                               // 原p位置之前结点指向插入结点位置
        return true;
    }
}

// 结点的删除：在链表l中删除位置p的结点
bool delete (List l, Position p)
{
    Position pre = l; // 默认l有头结点
    while (pre && pre->next != p)
    {
        pre = pre->next;
    }
    if (pre == NULL)
    {
        printf("删除位置参数错误\n");
        return false;
    }
    else
    {
        pre->next = p->next;
        free(p); // 释放p结点内存空间
        return true;
    }
}