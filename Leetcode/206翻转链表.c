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
// 反转链表
struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode *new_head = NULL;
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    while (head != NULL)
    {
        struct ListNode *temp = head->next; //先记录当前结点的下一个结点
        head->next = new_head;              //当前节点的next指针指向新链表new_head上
        new_head = head;                    // 接着让new_head移动到刚刚的head处
        head = temp;                        //让head移动到第下一个节点，进行下一轮
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