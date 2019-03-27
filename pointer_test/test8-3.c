//对输入的三个整数按从大到小排列输出，用函数处理，并且用指针类型的数据做函数参数

#include <stdio.h>
int main()
{
    void sort(int *, int *, int *);
    int t1, t2, t3;
    int *a = &t1, *b = &t2, *c = &t3; // 写法二，先把整型变量的地址给指针变量，再直接给指针变量地址存储空间放值
    printf("please input tow number:");
    scanf("%d,%d,%d", a, b, c);
    /* scanf("%d,%d,%d",&t1,&t2,&t3);  // 写法一，先给整型变量地址存储空间放值，在把地址给指针变量
    a = &t1;
    b = &t2;
    c = &t3; */
    printf("1---a = %d, b = %d, c = %d  &a = %d, &b = %d, &c = %d\n", *a, *b, *c, a, b, c);
    sort(a, b, c);
    printf("the order from big to small is %d, %d, %d\n", *a, *b, *c);
    return 0;
}

void sort(int *x, int *y, int *z)
{
    void swap(int *, int *);
    if (*x < *y)
    {
        swap(x, y);
        printf("1---x = %d, y = %d, z = %d  &x = %d, &y = %d, &z = %d\n", *x, *y, *z, x, y, z);
    }
    if (*x < *z)
    {
        swap(x, z);
        printf("2---x = %d, y = %d, z = %d  &x = %d, &y = %d, &z = %d\n", *x, *y, *z, x, y, z);
    }
    if (*y < *z)
    {
        swap(y, z);
        printf("3---x = %d, y = %d, z = %d  &x = %d, &y = %d, &z = %d\n", *x, *y, *z, x, y, z);
    }
}

void swap(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}