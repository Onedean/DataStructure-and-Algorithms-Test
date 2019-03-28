// 用函数调用实现字符串的复制（字符型指针变量做实参）

#include <stdio.h>

int main()
{
    void copy(char [], char []);
    char a[] = "pratice for string pointer";
    char b[] = "test string array for copy from a";
    char *from = a, *to = b;
    printf("string a = %s\nstring b = %s\n", from, to);
    copy(from, to);
    printf("string a = %s\nstring b = %s\n", from, to);
    printf("all string b = ");
    for(int i=0;i<33;i++){
        printf("%c",to[i]);
    }
    return 0;
}

void copy(char from[], char to[])
{
    int i=0;
    while (from[i] != '\0'){
        to[i]=from[i];
        i++;
    }
    to[i]='\0';
}
