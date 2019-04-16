#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 10
#define ERROR -1

typedef int ElementType;
typedef struct Lnode *list;

struct Lnode
{                              // ����һ�����Ա�Ľṹ������
    ElementType data[MAXSIZE]; // ��������������洢�ռ�˳�������Ա��еĸ�Ԫ��
    int last;                  // ���Ա�ĳ���
};

// ��ʼ��
list makeEmpty()
{
    list l = (list)malloc(sizeof(struct Lnode)); // ���ڴ��������ռ�
    l->last = -1;                                // ���ȱ�λ-1����ձ�
    return l;                                    // ����ָ�����Ա�Ľṹ��ָ�����l
}

// ���ң��β�Ϊ��ָ�����Ա�Ľṹ��ָ�����l �� ������ֵx
int find(list l, ElementType x)
{
    int i = 0; // i��¼���ҵ���λ��
    while (i <= l->last && l->data[i] != x)
    {
        i++;
    }
    return i > l->last ? ERROR : i;
}

// ���룬�β�Ϊ:
