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

/**
  * 解题思路：两两交换问题我们可以分解一下，1->2->3->4,交换后的结果是2->1->4->3
  *
  * 那么要改变的关系是，我们设head为pre，1为cur，2为post,我们两两一组开始变换
  *
  * 1.pre(head)的next原来为1，应该变了2
  *
  * 2.cur(1)的next原来为2，应该变为3
  *
  * 3.post(2)的next原来为3，应该变为1
  *
  * 只要按照这三步，两两循环即可
*/
// 两两交换链表节点（迭代法）
struct ListNode *swapPairs(struct ListNode *head)
{
    /* struct ListNode dummy;
    struct ListNode *pre = &dummy;
    pre->next = head;
    struct ListNode *cur;
    struct ListNode *post;
    while (pre->next != NULL && pre->next->next != NULL)
    {
        cur = pre->next;        //取cur
        post = pre->next->next; //取post
        pre->next = post;       //将head的next变为2
        cur->next = post->next; //将1的next变为3
        post->next = cur;       //将2的next变为1
        pre = pre->next->next;  //两两步进
    }
    return dummy.next; */
    struct ListNode *new_head = head, *temp = NULL;
    // 1->2->3->4->5->6->7  2->1->4-3->6->5->7
    while (head != NULL && head->next !=NULL)
    {
        temp = head->next->next->next;
        new_head = head->next;
        head->next->next = head;
        head->next = temp;
    }
    return head;
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