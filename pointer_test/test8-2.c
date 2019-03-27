// 输入a和b两个整数，按先大后小的顺序输出a和b

#include <stdio.h>
int main()
{
    int a, b, *p1, *p2;
    printf("please input two number:");
    scanf("%d,%d", &a, &b);
    p1 = &a;
    p2 = &b;
    if (*p1 < *p2)
    {
        p1 = &b;
        p2 = &a;
    }
    printf("%d,%d\n%d,%d\n", p1, p2, &a, &b);
    printf("The order from big to small is %d,%d", *p1, *p2);
    return 0;
}