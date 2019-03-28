// （定义和使用函数指针变量调用函数）输入两个整数，让用户选择1或2,1调用max函数求大值，2调用min函数求小值

#include <stdio.h>
int main()
{
    int max(int, int);  // 声明max函数
    int min(int, int);  // 声明min函数
    int (*p)(int, int); // 定义函数指针变量
    int x, y, choose;
    printf("please input tow number:");
    scanf("%d,%d", &x, &y);
    printf("please input your choose 1(max) or 2(min):");
    scanf("%d", &choose);
    if (choose == 1)
    {
        p = max; // 使函数指针变量指向max函数
        printf("max is ");
    }
    else if (choose == 2)
    {
        p = min; // 使函数指针变量指向min函数
        printf("min is ");
    }
    printf("%d", (*p)(x, y)); // 调用函数指针变量并输出
    return 0;
}

int max(int x, int y)
{
    return x > y ? x : y;
}

int min(int x, int y)
{
    return x < y ? x : y;
}