/* ���ýṹ������ͽṹ��ָ�����������������
        ��һ���ṹ�������ֵ���ݸ���һ�������ķ�����3�֣���
            1.�ýṹ������ĳ�Ա����������ֵ���ݡ�
            2.�ýṹ�������ʵ�Σ���ֵ���ݡ�
            3.��ָ��ṹ�������������Ԫ�أ��Ľṹ��ָ�������ʵ�Σ���ַ���ݡ�
 */

// ��n���ṹ��������ڰ���ѧ�š����������ſγɼ���Ҫ�����ƽ���ɼ���ߵ�ѧ��ȫ����Ϣ

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
    input(p); // �ýṹ��ָ�������ʵ�Σ����ݽṹ�������׵�ַ
    print(max(p));  // �ýṹ��ָ�������ʵ�Σ����ݽṹ�������׵�ַ�����ؽṹ������Ԫ�أ����ṹ���������ʵ�Σ�����ֵ
    return 0;
}

void input(struct Student stu[])
{
    struct Student *p;
    printf("����������ͬѧ��Ϣ:\n");
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
    printf("�ɼ���ߵ�ͬѧ��Ϣ��:\n");
    printf("%d\t%s\t%5.2f\t%5.2f\t%5.2f\t%5.2f", stud.num, stud.name, stud.score[0], stud.score[1], stud.score[2], stud.aver);
}