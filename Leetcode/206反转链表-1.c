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

// 反转链表（迭代法）
struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode *new_head = NULL, *temp = NULL;
    if (!head || !head->next)
    {
        return head;
    }
    while (head != NULL)
    {
        temp = head->next;     // 临时记录指针一直指向当前节点的下一个结点，防止断链找不到
        head->next = new_head; // 当前节点的next指针链到新节点上
        new_head = head;       // 新节点移动到刚才节点上，使得下次能够倒序链接节点
        head = temp;           // 当前节点移动到一开始保存的下一个结点
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