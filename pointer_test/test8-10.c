//定义一个字符数组，输出该字符数组和第八个值（通过指针引用字符串）

#include <stdio.h>
int main()
{
    char str1[] = "test for char pointer";
    printf("%s\n", str1);
    printf("%c\n", str1); //这里为什么输出0？转换为16进制取8个字节即最后两位转换为对应10进制对应ascii码表字符
    printf("%d\n", &str1[0]);
    printf("%c\n", str1[7]);

    char *str2 = "test for char pointer";
    printf("%s\n", str2);  // 注意这里%s是输出字符串所用的格式，在给出字符指针变量名时，系统会str2所指向的第1个字符，然后自动使str2加1，使之指向下一个字符继续输出，直到遇到字符串结束标志'\0'
    printf("%c\n", *str2); // 注意这里%c是输出字符，所以字符指针变量所在地址前加*指向对应字符
    printf("%c\n", *(str2 + 7));
}