/* 
    动态内存分配（堆）与指向它的指针变量：
        malloc函数：
            函数原型：void *malloc(unsigned int size);
            作用：在内存的动态存储区中分配一个长度为size的连续空间，形参为无符号整型（非负数）
                 返回所分配区域的第一个字节的地址，此函数是一个指针函数，指向头位置。未分配成功返回NULL（空指针）
        calloc函数：
            函数原型：void *calloc(unsigned n,unsigned size);
            作用：在内存的动态存储区中分配n个长度为size的连续空间，一般可以为一维数组开辟动态存储空间，n为数组
                 元素个数，每个元素长度为size，函数返回指向分配域起始位置的指针，未分配成功返回NULL（空指针）
        free函数：
            函数原型：void free(void *p);
            作用：释放指针变量p所指向的动态空间，使其能被再利用，p是最近一次调用calloc或malloc函数时所得到的
                 函数返回值，free函数无返回值
        realloc函数：
            函数原型：void *realloc(void *p,unsigned int size);
            作用：修改已经通过malloc或calloc函数获得的动态存储空间大小为size，进行重新分配。分配不成功则返回NULL
    注：1、上述4个函数什么在stdlib.h头文件中
        2、C99标准定义上述4个函数的基类型为void类型，所以指向不同类型数据会自动转换
        3、注意如下面：void类型指针指向一个地址，虽然地址相等，但输出这个指针变量则会报错，因为空类型指针是无指向性的
            int a = 3;
            void *q = &a;
            printf("%d %d %d",&a,q,*q);
 */

// 建立动态数组，输入5个学生的成绩，输出不合格者成绩
#include <stdio.h>
#include <stdlib.h>
int main()
{
    void check(int *);
    int *p;
    p = (int *)malloc(5 * sizeof(int)); // 开辟动态内存区，将void类型地址转换为整型地址赋值给指针变量
    // p = malloc(5 * sizeof(int));  // 这样也可以，不强制转换也会自动转换，一般为了规范会写一下
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", p + i);
    }
    check(p);
    return 0;
}

void check(int *p)
{
    printf("they are fail score:");
    for (int i = 0; i < 5; i++)
    {
        if (*(p + i) < 60)
        {
            printf("%d ", *(p + i));
        }
    }
}