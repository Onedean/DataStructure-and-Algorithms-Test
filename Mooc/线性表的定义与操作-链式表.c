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

// ����ֵ��������l�в���ֵx��λ��
struct Lnode *find(List l, ElementType x)
{
    Position p = l; // ָ��ͷ���
    while (p && p->data != x)
    {                // �жϲ��ҵ�����ҵ���β
        p = p->next; // pָ��ǰ������һ�����
    }
    return p ? p : NULL;
}

// ���Ĳ���:������l��λ��p֮ǰ����ֵx
bool insert(List l, ElementType x, Position p)
{
    Position pre = l; // Ĭ��l��ͷ��㣬������뵽��ͷ����ִ���
    // ����p֮ǰ��һ�����λ��
    while (pre && pre->next != p)
    {
        pre = pre->next;
    }
    if (pre == NULL)
    {
        printf("����λ�ò�������\n");
        return false;
    }
    else
    {
        List temp = (List)malloc(sizeof(struct Lnode)); // ���������ռ�
        temp->data = x;                                 // �����㸳ֵ
        temp->next = p;                                 // ������ָ����һ��pλ��
        pre->next = temp;                               // ԭpλ��֮ǰ���ָ�������λ��
        return true;
    }
}

// ����ɾ����������l��ɾ��λ��p�Ľ��
bool delete (List l, Position p)
{
    Position pre = l; // Ĭ��l��ͷ���
    while (pre && pre->next != p)
    {
        pre = pre->next;
    }
    if (pre == NULL)
    {
        printf("ɾ��λ�ò�������\n");
        return false;
    }
    else
    {
        pre->next = p->next;
        free(p); // �ͷ�p����ڴ�ռ�
        return true;
    }
}