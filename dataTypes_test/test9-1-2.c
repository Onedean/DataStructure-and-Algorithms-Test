/*  һ������ֵ��
        1���ṹ�����ͱ����ĳ�Ա�����ǽṹ������
            �﷨���ṹ�������.��Ա��
            struct Student
            {
                int age;
            } stu1 = {20};
            a = stu1.age;
        2���ṹ�����ͱ����ĳ�Ա�������ǽṹ������
            �﷨���ṹ�������.��Ա��.��Ա����һֱ�ó�Ա�����.�ҵ���ͼ���Ա��
            struct Date
            {
                int month;
            }
            struct Student
            {
                struct Date birthday;
            } stu1 = {{10}};
            a = stu1.birthday.month;
    ��������ַ��
        1���������ýṹ������ĵ�ַ
            printf("%d",&stu1.age);
        2���������ýṹ�������Ա�ĵ�ַ
            printf("%d",&stu1);
    ����ע�⣺
        1��ͬ���͵Ľṹ��������Ի��ำֵ
            struct teacher{
                char sex;
                int age;
            } t1 = {'M', 30},t2={'W', 35};
            t2 = t1;
        2���ṹ������ĳ�Ա�������λͬ��ͨ����
            t1.age++;
            int sum = t1.age + t2.age;
 */

// ��������ѧ����ѧ�š������ͳɼ�������ɼ��ϸߵ�ѧ��ȫ����Ϣ����ȶ����
#include<stdio.h>
struct Student{
    int number;
    char name[20];
    float score;
};
int main(){
    void print(struct Student);  // ע��˴�print���������������û��Զ����struct�ṹ�����ͣ���Ҫ�ڽṹ���������֮��
    struct Student stu1,stu2;
    scanf("%d %s %f",&stu1.number,stu1.name,&stu1.score);  // ע������name���������������ǵ�ַ���ʲ��ؼ�&
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