#include<stdio.h>
int main(){
    int a[3][4] = {1,3,5,7,9,11,13,15,17,19,21,23};
    int (*p)[4],i,j;  // 定义一维数组的指针变量
    //int *p,i,j;
    p = a;  // 指向数组的第0行
    printf("please input row and colum:");
    scanf("%d,%d",&i,&j);
    printf("a[%d,%d]=%d\n",i,j,*(*(p+i)+j));  // 前加一维数组行字节长度，后加一维数组的列字节长度
    //printf("a[%d,%d]=%d\n",i,j,*(p+i));
    return 0;
}