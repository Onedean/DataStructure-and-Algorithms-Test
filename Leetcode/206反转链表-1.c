/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(struct ListNode)
struct ListNode
{
    int val;
    struct ListNode *next;
};
int n = 0;
struct ListNode *creat()
{
    struct ListNode *head = NULL;
    struct ListNode *p1, *p2;
    p2 = p1 = (struct ListNode *)malloc(LEN);
    scanf("%d", &p1->val);
    while (p1->val != -1)
    {
        n++;
        if (n == 1)
        {
            head = p1;
        }
        else
        {
            p2->next = p1;
        }
        p2 = p1;
        p1 = (struct ListNode *)malloc(LEN);
        scanf("%d", &p1->val);
    }
    p2->next = NULL;
    return head;
}

// ��ת������������
struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode *new_head = NULL, *temp = NULL;
    if (!head || !head->next)
    {
        return head;
    }
    while (head != NULL)
    {
        temp = head->next;     // ��ʱ��¼ָ��һֱָ��ǰ�ڵ����һ����㣬��ֹ�����Ҳ���
        head->next = new_head; // ��ǰ�ڵ��nextָ�������½ڵ���
        new_head = head;       // �½ڵ��ƶ����ղŽڵ��ϣ�ʹ���´��ܹ��������ӽڵ�
        head = temp;           // ��ǰ�ڵ��ƶ���һ��ʼ�������һ�����
    }
    return new_head;
}

void print(struct ListNode *move)
{
    while (move != NULL)
    {
        printf("%d\t", move->val);
        move = move->next;
    }
}
int main()
{
    print(reverseList(creat()));
    return 0;
}