/*  一、定义结构体类型变量（3种方法）：
        1、先声明后定义
            struct Student
            {
                int age;
                char name[10];
            };
            struct Student stu1,stu2;
        2、声明的同时定义
            struct Student
            {
                int age;
                char name[10];
            }stu1,stu2;
        3、不指定类型名直接定义结构体类型变量
            struct
            {
                int age;
                char name[10];
            }stu1,stu2;
    二、结构体变量的初始化（2种）：
        1、声明定义结构体变量时初始化赋初值
            struct Student
            {
                int age;
                char name[10];
            }stu1={20,"dean"},stu2{18,"one"};
        2、定义结构体变量时对其成员初始化
            struct Student
            {
                int age;
                char name[10];
            }；
            struct Student stu1 = {.age = 20};
 */

#include <stdio.h>
int main()
{
    struct Date  //声明一个结构体类型
    {
        int month;
        int day;
        int year;
    };
    struct Student  // 声明定义并初始化结构体变量a，b
    {
        long int num;
        char name[20];
        char sex;
        char addr[20];
        struct Date birthday;
    } a = {100, "dean", 'M', "Hefei", {3, 10, 1998}}, b = {200, "superbee", 'M', "Korean", {8, 8, 1988}};
    struct Student c = {  // 定义结构体变量c并初始化部分内部成员
        .num = 300,
        .name = "dayday",
        .sex = 'W',
        .addr = "England",
        .birthday.year = 2008};
    printf("no.%d  name:%s  sex:%c  address:%s year:%d \n", a.num, a.name, a.sex, a.addr, a.birthday.year);
    printf("no.%d  name:%s  sex:%c  address:%s year:%d \n", b.num, b.name, b.sex, b.addr, b.birthday.year);
    printf("no.%d  name:%s  sex:%c  address:%s year:%d \n", c.num, c.name, c.sex, c.addr, c.birthday.year);
    return 0;
}