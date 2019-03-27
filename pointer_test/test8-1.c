//通过指针变量访问整型变量

#include <stdio.h>
int main()
{
    int a = 100, b = 10;
    int *pointer_1, *pointer_2;
    pointer_1 = &a; // pointer：指针变量本身  // 赋值为变量a的地址，*pointer指向变量a的地址
    pointer_2 = &b;
    printf("the value a = %d, the value b = %d\n", a, b);
    printf("the pointer a = %d, the pointer b = %d\n", *pointer_1, *pointer_2);
    /* pointer_1 = a;  // 这种做法是错的，给指针变量赋值给变量a的值，*pointer指向的地址为变量a值的地址，未知会报错
    pointer_2 = b;
    printf("the pointer a = %d, the pointer b = %d\n",* pointer_1,* pointer_2); */
    return 0;
}