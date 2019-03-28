// （用指向函数的指针做函数参数）两个整数a，b输入1,2,3分别调用求最大、求最小、求和函数

#include <stdio.h>
int main()
{
    void fun(int *, int *, void (*)(int *, int *)); // 定义fun函数包括两个整型指针变量和一个空型函数指针变量
    void max(int *, int *);
    void min(int *, int *);
    void sum(int *, int *);
    int a, b, choose, *x = &a, *y = &b;
    printf("please input tow number:");
    scanf("%d,%d", x, y);
    printf("please input your choose 1(max) or 2(min) or 3(sum):");
    scanf("%d", &choose);
    switch (choose)
    {
    case 1:
        fun(x, y, max); // 最后一个实参是将max函数指针（即入口地址）传给空型函数指针变量
        break;
    case 2:
        fun(x, y, min); // 最后一个实参是将min函数指针（即入口地址）传给空型函数指针变量
        break;
    case 3:
        fun(x, y, sum); // 最后一个实参是将sum函数指针（即入口地址）传给空型函数指针变量
        break;
    default:
        printf("error data error!");
        break;
    }
    return 0;
}

void fun(int *x, int *y, void (*p)(int *, int *))
{
    (*p)(x, y);  // 由传入的指针变量和函数指针（入口地址）调用相应函数
}

void max(int *x, int *y)
{
    printf("max is %d", *x > *y ? *x : *y);
}

void min(int *x, int *y)
{
    printf("min is %d", *x < *y ? *x : *y);
}

void sum(int *x, int *y)
{
    printf("sum is %d", *x + *y);
}