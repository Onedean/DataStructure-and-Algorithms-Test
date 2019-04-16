#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 10
#define ERROR -1

typedef int ElementType;
typedef struct Lnode *list;

struct Lnode
{                              // 声明一个线性表的结构体类型
    ElementType data[MAXSIZE]; // 利用数组的连续存储空间顺序存放线性变中的各元素
    int last;                  // 线性表的长度
};

// 初始化
list makeEmpty()
{
    list l = (list)malloc(sizeof(struct Lnode)); // 向内存申请分配空间
    l->last = -1;                                // 长度标位-1代表空表
    return l;                                    // 返回指向线性表的结构体指针变量l
}

// 查找，形参为：指向线性表的结构体指针变量l 和 查找数值x
int find(list l, ElementType x)
{
    int i = 0; // i记录查找到的位置
    while (i <= l->last && l->data[i] != x)
    {
        i++;
    }
    return i > l->last ? ERROR : i;
}

// 插入，形参为:
