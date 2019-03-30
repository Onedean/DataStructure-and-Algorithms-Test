// （结构体数组）编写一个统计选票的程序，10个选民先后输出候选人姓名，最后输出个人的票结果

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