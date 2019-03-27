// 键盘输入n个数，将这n个数反向输出

#include <stdio.h>
int main()
{
    void sort(int *, int);
    int a[50], *p = a, number;
    printf("how many number here:");
    scanf("%d", &number);
    for (int i = 0; i < number; i++)
    {
        scanf("%d", p++);
    }
    printf("the original array is:");
    for (p = a; p < a + number; p++)
    {
        printf("%4d", *p);
    }
    sort(a, number);
    printf("\nthe reverse array is:");

    for (p = a; p < a + number; p++)
    {
        printf("%4d", *p);
    }
    return 0;
}
void sort(int *q, int n)
{
    int *x = q;
    int *y = q + n - 1;
    int temp;
    for (; x < q + (n - 1) / 2; x++, y--)
    {
        temp = *x;
        *x = *y;
        *y = temp;
    }
}