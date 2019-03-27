// 按3*4格式输出二维数组

#include <stdio.h>
int main()
{
    int arr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    for (int *p = *arr; p < *arr + 12; p++)  // p指向的*arr是第1行1列的列指针，每次+1加的是列字节长度
    {
        if((p-*arr)%4==0 && p!=*arr){  // p-*arr编译时自动做自地址长度/整型字节长度即得到相差个数，取模每4位换行
            printf("\n");
        }
        printf("%4d",*p);
    }
    
    printf("\n\n");

    for (int *p = arr[0]; p < arr[0] + 12; p++)  // p指向的arr[0]是第1行1列的列指针，每次+1加的是列字节长度
    {
        if((p-arr[0])%4==0 && p!=arr[0]){  // p-arr[0]编译时自动做自地址长度/整型字节长度即得到相差个数，取模每4位换行
            printf("\n");
        }
        printf("%4d",*p);
    }
    return 0;
}