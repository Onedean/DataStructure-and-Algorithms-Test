/* 结构体指针：
    1.指向结构体变量的指针
        指向：一个结构体变量的起始地址
        注意：
            a、指针变量的基类型必须与结构体变量的类型相同
            b、结构体指针变量通过成员运算符.来引用成员（.优先级最高）
            c、(*p).可以用p->代替，->是指向运算符
    2.指向结构体数组中的元素的指针变量
        指向：一个结构体数组各元素的起始地址（数组名代表数组首元素起始地址）
        注意：
            a、指针变量每次加1增加的值为结构体数组一个元素总共所占的字节数
            b、不应该是指向数组元素中的某一成员，如果需要指向，则需要强制转换为结构体类型，此时指针变量+1恰好是下一元素的同一成员
 */

// 通过指向结构体变量的指针变量输出结构体变量中的成员信息

#include <stdio.h>
#include <string.h>
int main()
{
    struct Student
    {
        long num;
        char name[20];
        char sex;
        float score;
    };
    struct Student stu1; // 定义struct Student结构体类型
    struct Student *p;   // 定义struct Student结构体指针变量
    p = &stu1;           // 结构体指针变量指向stu1结构体变量
    stu1.num = 10101;
    strcpy(stu1.name, "oneDean");
    stu1.sex = 'M';
    stu1.score = 98.88;
    printf("NO.%ld\tname:%s\tsex:%c\t%5.2f\n", stu1.num, stu1.name, stu1.sex, stu1.score); // 通过结构体变量引用
    printf("NO.%ld\tname:%s\tsex:%c\t%5.2f\n", (*p).num, (*p).name, (*p).sex, (*p).score); // 通过结构体指针变量引用，成员运算符.优先级最高，故*p要包括号
    printf("NO.%ld\tname:%s\tsex:%c\t%5.2f\n", (*p).num, (*p).name, (*p).sex, (*p).score); // 通过结构体指针变量引用，成员运算符.优先级最高，故*p要包括号
    printf("NO.%ld\tname:%s\tsex:%c\t%5.2f\n", p->num, p->name, p->sex, p->score);         // 通过指向运算符引用，(*p).可以用p->代替

    printf("\n");

    struct Student stu[3] = {{100, "dean", 'M', 60.88}, {200, "one", 'W', 88.88}, {300, "zico", 'M', 99.88}};
    struct Student *pointer;
    printf("No.\tName\tsex\tage\n");
    for (pointer = stu; pointer < stu + 3; pointer++)  // 结构体指针变量指向stu结构体数组首元素地址
    {
        printf("%d\t%s\t%c\t%5.2f\n", pointer->num, pointer->name, pointer->sex, pointer->score);
    }
    return 0;
}