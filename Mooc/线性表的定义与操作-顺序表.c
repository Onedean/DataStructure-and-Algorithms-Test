#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 10
#define ERROR -1

typedef int ElementType;
typedef struct Lnode *List;

struct Lnode
{                              // ����һ�����Ա�Ľṹ������
    ElementType data[MAXSIZE]; // ��������������洢�ռ�˳�������Ա��еĸ�Ԫ��
    int length;                // ���Ա�ĳ���
};

// ��ʼ��
List makeEmpty()
{
    List l = (List)malloc(sizeof(struct Lnode)); // ���ڴ��������ռ�
    l->length = -1;                              // ���ȱ�λ-1����ձ�
    return l;                                    // ����ָ�����Ա�Ľṹ��ָ�����l
}

// ���ң��β�Ϊ��ָ�����Ա�Ľṹ��ָ�����l �� ������ֵx
int find(List l, ElementType x)
{
    int i = 0; // i��¼���ҵ���λ��
    while (i <= l->length && l->data[i] != x)
    {
        i++;
    }
    return i > l->length ? ERROR : i;
}

// ���룬�β�Ϊ:ָ�����Ա�Ľṹ��ָ�����l �� ����ֵ �� �����±�λ��
bool insert(List l, ElementType x, int p)
{
    if (l->length == MAXSIZE - 1) // ����ռ��Ƿ�����
    {
        printf("������\n");
        return false;
    }
    if (p < 0 || p > l->length + 1) // ������λ�úϷ���
    {
        printf("λ�ò��Ϸ�\n");
        return false;
    }
    for (int i = l->length; i >= p; i++) // ����p��lastλ��Ԫ�����κ���
    {
        l->data[i + 1] = l->data[i];
    }
    l->data[p] = x; // ������ֵx����pλ��
    l->length++;    // ���Ա���+1
    return true;    // ����ɹ�
}

// ɾ�����β�Ϊ��ָ�����Ա�Ľṹ��ָ�����l �� ����ֵ �� ɾ���±�λ��
bool delete (List l, int p)
{
    if (p < 0 || p > l->length)
    { // ���ɾ��λ�úϷ���
        prinf("ɾ��λ�ò��Ϸ�\n");
        return false;
    }
    for (int i = p + 1; i <= l->length; i++)
    {
        l->data[i - 1] = l->data[i];
    }
    l->length--; // �����ɾ�����һ��Ԫ�أ�ʵ���ϲ�û����ɾ���������Ǹ������Ա�ĳ��ȼٶ�ɾ�������һ��
    return true;
}
