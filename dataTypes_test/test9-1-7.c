// �������������ѧ����Ϣ�ĵ���̬����

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
    struct Student *head = NULL;             // ͷָ����ΪNULL���������
    struct Student *p1, *p2;                 // p2�Ǽ�¼��ǰ����ƶ�λ�õ�ָ�룬p1�����µĿ��ٽ���ָ��
    p2 = p1 = (struct Student *)malloc(LEN); // p1ָ�򿪱����µĽṹ���ֽڴ�С����ַ��p2�������½��
    scanf("%ld,%f", &p1->num, &p1->score);   // �������£���һ��ѧ�����Ľ����Ϣ
    while (p1->num != 0)                     // �������������ѧ��Ϊ0
    {
        n++;        // ��¼ѧ����
        if (n == 1) // �жϵ�ǰ��ͷָ�뻹����ͨ���ָ��
        {
            head = p1; // ͷָ��ָ����һ�����
        }
        else
        {
            p2->next = p1; // ��һ������Ա��nextָ��ָ����һ�����
        }
        p2 = p1;                               // p2���浽���½��
        p1 = (struct Student *)malloc(LEN);    // p1ָ�򿪱����µĽṹ���ֽڴ�С����ַ
        scanf("%ld,%f", &p1->num, &p1->score); // �������µĽ����Ϣ
    }
    p2->next = NULL; // ��β����Ա�е�nextָ����ΪNULL��ָ��
    return head;     // ����ͷָ��
}

void print(struct Student *move)
{
    printf("the %d student's information:\n", n);
    while (move != NULL) // �жϲ�Ϊ������
    {
        printf("num:%ld score:%5.2f\n", move->num, move->score);
        move = move->next; //�ƶ�ָ��
    }
}

int main()
{
    print(creat()); // ���ô���������������ͷָ����Ϊʵ��ַ���ݸ����������ӡ����
    return 0;
}