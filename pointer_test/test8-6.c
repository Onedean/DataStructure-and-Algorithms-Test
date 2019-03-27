// 用指针方法对10个整数按从小到大顺序排序

#include <stdio.h>
int main()
{
    void sort(int *, int);
    int a[10] = {10, 9, 6, 8, 7, 4, 5, 1, 3, 2}, *p = a;
    sort(p, 10);
    printf("the sorted array is:");
    for (p = a; p < a + 10; p++)
    {
        printf("%4d", *p);
    }
    return 0;
}

void sort(int *x, int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (*(x + i) > *(x + j))
            {
                temp = *(x + i);
                *(x + i) = *(x + j);
                *(x + j) = temp;
            }
        }
    }
}