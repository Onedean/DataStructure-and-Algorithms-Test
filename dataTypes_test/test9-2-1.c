/* 
    ����������
        ���壺
            ʹ�ø��Ǽ�������ͬһ���ڴ浫Ը��Ų�ͬ�����͵ı���
        �﷨��
            1�����������壺
            union Date{
                int i;
                char ch;
                float:f;
            };
            union Date a,b,c;
            2���������߶��壺
            union Date{
                int i;
                char ch;
                float:f;
            }a,b,c;
        �ڴ泤�ȣ�
            ������ĳ�Ա�ĳ��ȣ����ϱ����float�ͱ���ռ4���ֽڣ�����a,b,c��ռ4���ֽ�
        ���÷�ʽ��
            �������ù�ͬ�������ֻ�����ù�ͬ������еĳ�Ա
        ע�⣺
            1��ͬһ�ڴ�ο���������źü��ֲ�ͬ���͵ĳ�Ա������ÿһ˲��ֻ�ܴ������һ����Ա��������ͬʱ��ż���
                union Date{
                  int i;
                  char ch;
                  float f;
                }a;
                a.i = 97;
                printf("%d, a.i");  // 97
                printf("%c, a.i");  // 'a'
                printf("%f, a.i");  // 0.000000  ���︡������ôת���ģ�������
            2�����ԶԹ����������ʼ��������ʼ������ֻ����һ������
                union Date{
                  int i;
                  char ch;
                  float:f;
                };
                union Date a = {1, 'a', 1.5};  // ��
                union Date a = {16};  // ��
                union Date a = {.ch = 'f'};  // �ԣ�C99���ж�ָ����һ����Ա��ʼ��
            3����ʼ����ÿ�����¸�ֵ�����Ḳ�ǵ�֮ǰ��
            4������������ĵ�ַ�����ĸ���Ա�ĵ�ַ����ͬһ��ַ
            5�����ܶԹ������������ֵ���Լ���ͼ���ñ��������õ�һ��ֵ
            6��C99����ͬ���͵Ĺ�����������ำֵ
 */

#include <stdio.h>
struct Student
{
    int num;
    char name[20];
    char sex;
    char job;
    union { // ����һ���������������Ͳ����壬Ҳ����������������������ֱ�Ӻ���
        int clas;
        char position[10];
    } category;
} person[2];
int main()
{
    struct Student *p;
    for (p = person; p < person + 2; p++)
    {
        scanf("%d %s %c %c", &p->num, p->name, &p->sex, &p->job);
        if (p->job == 's')
        {
            scanf("%d", &p->category.clas); // �����ѧ��������༶
        }
        else if (p->job == 't')
        {
            scanf("%s", p->category.position); // �������ʦ������ְ��
        }
        else
        {
            printf("Input error!");
        }
    }
    printf("\n");
    printf("NO.\tname\tsex\tjob\tclass/position\n");
    for (p = person; p < person + 2; p++)
    {
        if (p->job == 's')
        {
            printf("%d\t%s\t%c\t%c\t%d\n", p->num, p->name, p->sex, p->job, p->category.clas);
        }
        else if (p->job == 't')
        {
            printf("%d\t%s\t%c\t%c\t%s\n", p->num, p->name, p->sex, p->job, p->category.position);
        }
    }
    return 0;
}