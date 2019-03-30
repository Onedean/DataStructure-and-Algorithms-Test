// （结构体数组）有5个学生的信息，包括学号姓名和成绩，要求按照成绩由高到低输出各学生信息

#include <Stdio.h>
#define N 5  // 定义符号常量N为5
struct Student
{
    int num;
    char name[20];
    float score;
};
int main()
{
    struct Student stu[5] = {{100, "one", 90}, {101, "dean", 88}, {102, "mu", 75}, {103, "chen", 100}, {104, "qi", 80}};
    struct Student temp;
    //const int n = 5;  // 定义常变量n为5，可以由上面#define N 5代替
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (stu[i].score < stu[j].score)
            {
                temp = stu[i];
                stu[i] = stu[j];
                stu[j] = temp;
            }
        }
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t%s\t%6.2f\n", stu[i].num, stu[i].name, stu[i].score);
    }
    return 0;
}