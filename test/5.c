//定义一个带参数的宏，找出两个数中的大者。分别把3，5；3+5，5-3两对数传递给宏来验证编写的宏是否正确。
#include <stdio.h>
#define MAX(m, n) (m > n ? m : n)
void main()
{
    int max = MAX(3+5,5-3);
    printf("max=%d", max);
}
