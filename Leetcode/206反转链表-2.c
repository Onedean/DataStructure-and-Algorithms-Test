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

// ��ת�����ݹ鷨��
struct ListNode *reverseList(struct ListNode *head)
{
    if (!head || !head->next)
    {
        return head; // ��һ�γ�ջ�������жϽ�����ջ������
    }
    else
    {
        struct ListNode *new_tail = reverseList(head->next); // һֱ��ջ�����µ�βָ��������һ���ڵ�
        head->next->next = head;                             // ÿ���ݹ�ջ�ڽ���һ���ڵ�����ǰһ���ڵ�
        head->next = NULL;                                   // ȷ�����һ���ڵ�ָ��NULL
        return new_tail;                                     // ʣ�µĳ�ջ�������õݹ�ջ���ط�ת֮�����ʱ�����β���
    }
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