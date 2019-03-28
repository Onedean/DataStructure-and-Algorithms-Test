// （指针数组）将若干个字符串按字母顺序由小到大输出

#include <stdio.h>
#include <string.h>
int main()
{
    void sort(char *[], int);                                   // 声明sort排序函数
    void print(char *[], int);                                  // 声明print打印函数
    char *name[] = {"one", "dean", "three", "four", "pointer"}; //定义指针数组，指向若干字符串常量,各自存放各自字符串常量首字母的地址，相当于定义了一组指向指针数据的指针
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", name + i); // 指针数组各元素存储的是字符串常量的首字母地址
    }
    printf("\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", *(name + i));  // 这里内存地址相差长度为各字符串常量长度加'\0'的1个长度
    }
    printf("\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%s ", *(name + i));
    }
    printf("\n");
    sort(name, 5);  // 传入指针数组和数值作为实参，调用排序函数
    print(name, 5); // 传入指针数组和数值作为实参，调用排序函数
    return 0;
}

void sort(char *name[], int n)
{
    char *temp;
    /* 下标法：
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(name[i], name[j]) > 0)
            {
                temp = name[i];
                name[i] = name[j];
                name[j] = temp;
            }
        }
    } */
    // 指针法：
    for (char **i = name; i < name + n - 1; i++)
    {
        for (char **j = i + 1; j < name + n; j++)
        {
            if (strcmp(*i, *j) > 0)
            {
                temp = *i;
                *i = *j;
                *j = temp;
            }
        }
    }
}

void print(char *name[], int n)
{
    /* 下标法：
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", name[i]);
    } */
    // 指针法：
    for (char **i = name; i < name + n; i++)
    {
        printf("%s ", *i);
    }
}