// 建立和输出三个学生信息的单向动态链表

#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(struct Student)
struct Student
{
    long int num;
    float score;
    struct Student *next;
};
int n = 0;

struct Student *creat()
{
    struct Student *head = NULL;             // 头指针置为NULL代表空链表
    struct Student *p1, *p2;                 // p2是记录当前结点移动位置的指针，p1是最新的开辟结点的指针
    p2 = p1 = (struct Student *)malloc(LEN); // p1指向开辟最新的结构体字节大小结点地址，p2跟随最新结点
    scanf("%ld,%f", &p1->num, &p1->score);   // 输入最新（第一个学生）的结点信息
    while (p1->num != 0)                     // 链表结束条件，学号为0
    {
        n++;        // 记录学生数
        if (n == 1) // 判断当前是头指针还是普通结点指针
        {
            head = p1; // 头指针指向下一个结点
        }
        else
        {
            p2->next = p1; // 上一个结点成员中next指针指向下一个结点
        }
        p2 = p1;                               // p2跟随到最新结点
        p1 = (struct Student *)malloc(LEN);    // p1指向开辟最新的结构体字节大小结点地址
        scanf("%ld,%f", &p1->num, &p1->score); // 输入最新的结点信息
    }
    p2->next = NULL; // 是尾结点成员中的next指针置为NULL无指向
    return head;     // 返回头指针
}

void print(struct Student *move)
{
    printf("the %d student's information:\n", n);
    while (move != NULL) // 判断不为空链表
    {
        printf("num:%ld score:%5.2f\n", move->num, move->score);
        move = move->next; //移动指针
    }
}

int main()
{
    print(creat()); // 调用创建链表函数，返回头指针作为实参址传递给输出函数打印链表
    return 0;
}