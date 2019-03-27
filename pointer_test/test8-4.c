// 输出数组中的全部元素

#include <stdio.h>
int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // 方法一：数组下标法
    for (int i = 0; i < 10; i++)
    {
        printf("%4d", a[i]);
    }
    printf("\n");

    // 方法二：指针法
    for (int i = 0; i < 10; i++)
    {
        printf("%4d", *(a + i));
    }
    printf("\n");

    // 方法三：指针法
    for (int i = 0, *p = a; i < 10; i++)
    {
        printf("%4d", *p++);
    }
    printf("\n");

    // 方法四：纯指针法(指针直接指向地址，速度最快)
    for (int *p = a; p < a + 10; p++)
    {
        printf("%4d", *p);
    }

    return 0;
}