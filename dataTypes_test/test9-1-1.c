/*  һ������ṹ�����ͱ�����3�ַ�������
        1������������
            struct Student
            {
                int age;
                char name[10];
            };
            struct Student stu1,stu2;
        2��������ͬʱ����
            struct Student
            {
                int age;
                char name[10];
            }stu1,stu2;
        3����ָ��������ֱ�Ӷ���ṹ�����ͱ���
            struct
            {
                int age;
                char name[10];
            }stu1,stu2;
    �����ṹ������ĳ�ʼ����2�֣���
        1����������ṹ�����ʱ��ʼ������ֵ
            struct Student
            {
                int age;
                char name[10];
            }stu1={20,"dean"},stu2{18,"one"};
        2������ṹ�����ʱ�����Ա��ʼ��
            struct Student
            {
                int age;
                char name[10];
            }��
            struct Student stu1 = {.age = 20};
 */

#include <stdio.h>
int main()
{
    struct Date  //����һ���ṹ������
    {
        int month;
        int day;
        int year;
    };
    struct Student  // �������岢��ʼ���ṹ�����a��b
    {
        long int num;
        char name[20];
        char sex;
        char addr[20];
        struct Date birthday;
    } a = {100, "dean", 'M', "Hefei", {3, 10, 1998}}, b = {200, "superbee", 'M', "Korean", {8, 8, 1988}};
    struct Student c = {  // ����ṹ�����c����ʼ�������ڲ���Ա
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