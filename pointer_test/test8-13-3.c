// 用函数调用实现字符串的复制（字符型指针变量做实参和形参）

#include <stdio.h>
int main()
{
    void copy(char *, char *);
    char *a = "pratice for string pointer";
    char arr[] = "test string array for copy from a", *b = arr; // 字符指针变量指向字符串常量时字符串常量的内容不可再赋值，故这里字符常量中的内容要被更改，所以用字符数组存储
    printf("string a = %s\nstring b = %s\n", a, b);
    copy(a, b);
    printf("string a = %s\nstring b = %s\n", a, b);
    return 0;
}

void copy(char *a, char *b)
{
    // 写法一：
    /* while (*a != '\0')
    {
        *b = *a;
        a++;
        b++;
    } */

    // 简化写法二：先赋值后判断
    /* while ((*b = *a) != '\0')
    {
        a++;
        b++;
    } */

    // 简化写法三：先赋值后判断再增加
    /* while ((*b++ = *a++) != '\0')
    {
    } */

    //简化写法四：'\0'ASCII码是0直接判断真假
    while (*b++ = *a++)
    {
    }

    *b = '\0';
}