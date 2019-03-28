// 将字符串a复制为字符串b，然后输出b

#include <stdio.h>
int main()
{
    // 数组法：
    char a[] = "test for copy string by index", b[20];
    int i;
    for (i = 0; *(a + i) != '\0'; i++)
    {
        *(b + i) = *(a + i);
    }
    *(b + i) = '\0';
    printf("string a is: %s\n", a); // 整体输出字符串a
    printf("string b is: ");
    for (int i = 0; *(b + i) != '\0'; i++)
    {
        printf("%c", *(b + i));
    }
    printf("\n");

    // 指针法：
    char x[] = "test for copy string by pure pointer", y[40];
    char *p1 = x, *p2 = y;
    for (; *p1 != '\0'; p1++, p2++)
    {
        *p2 = *p1;
    }
    *p2 = '\0';
    printf("string x is: %s\n", x); // 注意这里输出的是字符数组x和y，而不是字符指针p1和p2
    printf("string y is: %s\n", y);
    printf("*p1 = %c , *p2 = %c\n", *(p1 - 1), *(p2 - 1)); // 字符指针p1和p2此时已经指向最后字符串结束符'\0'地址了
    return 0;
}