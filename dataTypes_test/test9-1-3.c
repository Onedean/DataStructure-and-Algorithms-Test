// ���ṹ�����飩��дһ��ͳ��ѡƱ�ĳ���10��ѡ���Ⱥ������ѡ�����������������˵�Ʊ���

#include <stdio.h>
#include <string.h>
struct Person
{
    char name[20];
    int count;
} leader[3] = {{"zhang", 0}, {"wang", 0}, {"li", 0}};
int main()
{
    int i, j;
    char voteName[20];
    for (int i = 0; i < 10; i++)
    {
        scanf("%s", voteName);
        for (int j = 0; j < 3; j++)
        {
            if (strcmp(voteName, leader[j].name) == 0)
            {
                leader[j].count++;
            }
        }
    }
    printf("result:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%s:%d\n", leader[i].name, leader[i].count);
    }
    return 0;
}