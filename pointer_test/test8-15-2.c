// ����ָ������ָ����������������������a��b����1,2,3�ֱ�������������С����ͺ���

#include <stdio.h>
int main()
{
    void fun(int *, int *, void (*)(int *, int *)); // ����fun����������������ָ�������һ�����ͺ���ָ�����
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
        fun(x, y, max); // ���һ��ʵ���ǽ�max����ָ�루����ڵ�ַ���������ͺ���ָ�����
        break;
    case 2:
        fun(x, y, min); // ���һ��ʵ���ǽ�min����ָ�루����ڵ�ַ���������ͺ���ָ�����
        break;
    case 3:
        fun(x, y, sum); // ���һ��ʵ���ǽ�sum����ָ�루����ڵ�ַ���������ͺ���ָ�����
        break;
    default:
        printf("error data error!");
        break;
    }
    return 0;
}

void fun(int *x, int *y, void (*p)(int *, int *))
{
    (*p)(x, y);  // �ɴ����ָ������ͺ���ָ�루��ڵ�ַ��������Ӧ����
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