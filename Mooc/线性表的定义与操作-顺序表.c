#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 10
#define ERROR -1

typedef int ElementType;
typedef struct Lnode *List;

struct Lnode
{                              // 声明一个线性表的结构体类型
    ElementType data[MAXSIZE]; // 利用数组的连续存储空间顺序存放线性变中的各元素
    int length;                // 线性表的长度
};

// 初始化
List makeEmpty()
{
    List l = (List)malloc(sizeof(struct Lnode)); // 向内存申请分配空间
    l->length = -1;                              // 长度标位-1代表空表
    return l;                                    // 返回指向线性表的结构体指针变量l
}

// 查找，形参为：指向线性表的结构体指针变量l 和 查找数值x
int find(List l, ElementType x)
{
    int i = 0; // i记录查找到的位置
    while (i <= l->length && l->data[i] != x)
    {
        i++;
    }
    return i > l->length ? ERROR : i;
}

// 插入，形参为:指向线性表的结构体指针变量l 和 插入值 和 插入下标位置
bool insert(List l, ElementType x, int p)
{
    if (l->length == MAXSIZE - 1) // 检查表空间是否已满
    {
        printf("表已满\n");
        return false;
    }
    if (p < 0 || p > l->length + 1) // 检查插入位置合法性
    {
        printf("位置不合法\n");
        return false;
    }
    for (int i = l->length; i >= p; i++) // 倒序将p到last位置元素依次后移
    {
        l->data[i + 1] = l->data[i];
    }
    l->data[p] = x; // 将插入值x赋给p位置
    l->length++;    // 线性表长度+1
    return true;    // 插入成功
}

// 删除，形参为：指向线性表的结构体指针变量l 和 插入值 和 删除下标位置
bool delete (List l, int p)
{
    if (p < 0 || p > l->length)
    { // 检查删除位置合法性
        prinf("删除位置不合法\n");
        return false;
    }
    for (int i = p + 1; i <= l->length; i++)
    {
        l->data[i - 1] = l->data[i];
    }
    l->length--; // 如果是删除最后一个元素，实际上并没真正删除，而是是根据线性表的长度假定删除了最后一个
    return true;
}
