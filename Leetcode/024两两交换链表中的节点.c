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
  * ����˼·�����������������ǿ��Էֽ�һ�£�1->2->3->4,������Ľ����2->1->4->3
  *
  * ��ôҪ�ı�Ĺ�ϵ�ǣ�������headΪpre��1Ϊcur��2Ϊpost,��������һ�鿪ʼ�任
  *
  * 1.pre(head)��nextԭ��Ϊ1��Ӧ�ñ���2
  *
  * 2.cur(1)��nextԭ��Ϊ2��Ӧ�ñ�Ϊ3
  *
  * 3.post(2)��nextԭ��Ϊ3��Ӧ�ñ�Ϊ1
  *
  * ֻҪ����������������ѭ������
*/
// ������������ڵ㣨��������
struct ListNode *swapPairs(struct ListNode *head)
{
    /* struct ListNode dummy;
    struct ListNode *pre = &dummy;
    pre->next = head;
    struct ListNode *cur;
    struct ListNode *post;
    while (pre->next != NULL && pre->next->next != NULL)
    {
        cur = pre->next;        //ȡcur
        post = pre->next->next; //ȡpost
        pre->next = post;       //��head��next��Ϊ2
        cur->next = post->next; //��1��next��Ϊ3
        post->next = cur;       //��2��next��Ϊ1
        pre = pre->next->next;  //��������
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