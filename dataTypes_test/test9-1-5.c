/* �ṹ��ָ�룺
    1.ָ��ṹ�������ָ��
        ָ��һ���ṹ���������ʼ��ַ
        ע�⣺
            a��ָ������Ļ����ͱ�����ṹ�������������ͬ
            b���ṹ��ָ�����ͨ����Ա�����.�����ó�Ա��.���ȼ���ߣ�
            c��(*p).������p->���棬->��ָ�������
    2.ָ��ṹ�������е�Ԫ�ص�ָ�����
        ָ��һ���ṹ�������Ԫ�ص���ʼ��ַ������������������Ԫ����ʼ��ַ��
        ע�⣺
            a��ָ�����ÿ�μ�1���ӵ�ֵΪ�ṹ������һ��Ԫ���ܹ���ռ���ֽ���
            b����Ӧ����ָ������Ԫ���е�ĳһ��Ա�������Ҫָ������Ҫǿ��ת��Ϊ�ṹ�����ͣ���ʱָ�����+1ǡ������һԪ�ص�ͬһ��Ա
 */

// ͨ��ָ��ṹ�������ָ���������ṹ������еĳ�Ա��Ϣ

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
    struct Student stu1; // ����struct Student�ṹ������
    struct Student *p;   // ����struct Student�ṹ��ָ�����
    p = &stu1;           // �ṹ��ָ�����ָ��stu1�ṹ�����
    stu1.num = 10101;
    strcpy(stu1.name, "oneDean");
    stu1.sex = 'M';
    stu1.score = 98.88;
    printf("NO.%ld\tname:%s\tsex:%c\t%5.2f\n", stu1.num, stu1.name, stu1.sex, stu1.score); // ͨ���ṹ���������
    printf("NO.%ld\tname:%s\tsex:%c\t%5.2f\n", (*p).num, (*p).name, (*p).sex, (*p).score); // ͨ���ṹ��ָ��������ã���Ա�����.���ȼ���ߣ���*pҪ������
    printf("NO.%ld\tname:%s\tsex:%c\t%5.2f\n", (*p).num, (*p).name, (*p).sex, (*p).score); // ͨ���ṹ��ָ��������ã���Ա�����.���ȼ���ߣ���*pҪ������
    printf("NO.%ld\tname:%s\tsex:%c\t%5.2f\n", p->num, p->name, p->sex, p->score);         // ͨ��ָ����������ã�(*p).������p->����

    printf("\n");

    struct Student stu[3] = {{100, "dean", 'M', 60.88}, {200, "one", 'W', 88.88}, {300, "zico", 'M', 99.88}};
    struct Student *pointer;
    printf("No.\tName\tsex\tage\n");
    for (pointer = stu; pointer < stu + 3; pointer++)  // �ṹ��ָ�����ָ��stu�ṹ��������Ԫ�ص�ַ
    {
        printf("%d\t%s\t%c\t%5.2f\n", pointer->num, pointer->name, pointer->sex, pointer->score);
    }
    return 0;
}