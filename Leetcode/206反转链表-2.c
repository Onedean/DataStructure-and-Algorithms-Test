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

// 反转链表（递归法）
struct ListNode *reverseList(struct ListNode *head)
{
    if (!head || !head->next)
    {
        return head; // 第一次出栈操作，判断结束入栈的条件
    }
    else
    {
        struct ListNode *new_tail = reverseList(head->next); // 一直入栈到将新的尾指针等于最后一个节点
        head->next->next = head;                             // 每个递归栈内将后一个节点链向前一个节点
        head->next = NULL;                                   // 确保最后一个节点指向NULL
        return new_tail;                                     // 剩下的出栈操作，该递归栈返回反转之后的临时链表的尾结点
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