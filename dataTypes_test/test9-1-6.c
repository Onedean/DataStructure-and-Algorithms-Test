/* （用结构体变量和结构体指针变量做函数参数）
        将一个结构体变量的值传递给另一个函数的方法（3种）：
            1.用结构体变量的成员做参数，“值传递”
            2.用结构体变量做实参，“值传递”
            3.用指向结构体变量（或数组元素）的结构体指针变量做实参，“址传递”
 */

// 有n个结构体变量，内包含学号、姓名、三门课成绩。要求输出平均成绩最高的学生全部信息

#include <stdio.h>
#define N 3
struct Student
{
    int num;
    char name[20];
    float score[3];
    float aver;
};

int main()
{
    void input(struct Student[]);
    struct Student max(struct Student[]);
    void print(struct Student);
    struct Student stu[3], *p = stu;
    input(p); // 用结构体指针变量做实参，传递结构体数组首地址
    print(max(p));  // 用结构体指针变量做实参，传递结构体数组首地址，返回结构体数组元素（即结构体变量）做实参，传递值
    return 0;
}

void input(struct Student stu[])
{
    struct Student *p;
    printf("请输入所有同学信息:\n");
    for (p = stu; p < stu + N; p++)
    {
        scanf("%d %s %f %f %f", &p->num, &p->name, &p->score[0], &p->score[1], &p->score[2]);
        p->aver = (p->score[0] + p->score[1] + p->score[2]) / N;
    }
}

struct Student max(struct Student stu[])
{
    int m = 0;
    for (int i = 1; i < N; i++)
    {
        if (stu[i].aver > stu[m].aver)
        {
            m = i;
        }
    }
    return stu[m];
}

void print(struct Student stud)
{
    printf("成绩最高的同学信息是:\n");
    printf("%d\t%s\t%5.2f\t%5.2f\t%5.2f\t%5.2f", stud.num, stud.name, stud.score[0], stud.score[1], stud.score[2], stud.aver);
}