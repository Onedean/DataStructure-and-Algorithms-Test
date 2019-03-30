/*  一、引用值：
        1、结构体类型变量的成员本身不是结构体类型
            语法：结构体变量名.成员名
            struct Student
            {
                int age;
            } stu1 = {20};
            a = stu1.age;
        2、结构体类型变量的成员本身仍是结构体类型
            语法：结构体变量名.成员名.成员名（一直用成员运算符.找到最低级成员）
            struct Date
            {
                int month;
            }
            struct Student
            {
                struct Date birthday;
            } stu1 = {{10}};
            a = stu1.birthday.month;
    二、引用址：
        1、可以引用结构体变量的地址
            printf("%d",&stu1.age);
        2、可以引用结构体变量成员的地址
            printf("%d",&stu1);
    三、注意：
        1、同类型的结构体变量可以互相赋值
            struct teacher{
                char sex;
                int age;
            } t1 = {'M', 30},t2={'W', 35};
            t2 = t1;
        2、结构体变量的成员作用与地位同普通变量
            t1.age++;
            int sum = t1.age + t2.age;
 */

// 输入两个学生的学号、姓名和成绩，输出成绩较高的学生全部信息，相等都输出
#include<stdio.h>
struct Student{
    int number;
    char name[20];
    float score;
};
int main(){
    void print(struct Student);  // 注意此处print函数声明中用了用户自定义的struct结构体类型，需要在结构体声明语句之后
    struct Student stu1,stu2;
    scanf("%d %s %f",&stu1.number,stu1.name,&stu1.score);  // 注意这里name本身是数组名就是地址，故不必加&
    scanf("%d %s %f",&stu2.number,stu2.name,&stu2.score);
    printf("the higher score is:\n");
    if(stu1.score>stu2.score){
        print(stu1);
    }else if(stu1.score<stu2.score){
        print(stu2);
    }else{
        print(stu1);
        print(stu2);
    }
}

void print(struct Student stu){
    printf("%d %s %5.2f\n",stu.number,stu.name,stu.score);
}