//（返回指针值的函数）查找学生中有挂科的学生号及其全部成绩

#include <stdio.h>
int main()
{
    float score[][4] = {{60, 70, 80, 90}, {56, 89, 67, 88}, {34, 78, 90, 66}};
    float *search(float(*)[], int); // 声明返回指针值类型的函数
    float *p;
    for (int i = 0; i < 3; i++)
    {
        p = search(score + i, 4); // 调用返回指针类型函数返回给一个指针变量
        if (p == *(score + i))    // 如果指针变量等于相应返回的列指针
        {
            printf("no.%d falied student:", i + 1);
            for (int j = 0; j < 4; j++)
            {
                printf("%8.2f", *(p + j));
            }
            printf("\n");
        }
    }

    return 0;
}

float *search(float (*p)[4], int n)
{
    float *pointer = NULL; // 初始化指针值
    for (int i = 0; i < n; i++)
    {
        if (*(*p + i) < 60)
        {
            pointer = *p; // 指针变量等于指向列指针
        }
    }
    return pointer; // 返回指针值

    /* 写法二：指针法
    float *y = NULL;
    for (float *x = *p; x < *p + n; x++)
    {
        if (*x < 60)
        {
            y = *p;
        }
    }
    return y; */
}
