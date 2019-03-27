//一维数组指针翻转
#include<stdio.h>
void main(){
    int fun(int *a,int n);
    int array[10] = {1,2,3,4,5,6,7,8,9,10};
    int *pointer;
    for(pointer = array;pointer < array + 10;pointer++){
        printf("%3d",*pointer);
    }
    printf("\n");
    fun(array,10);
    for(pointer = array;pointer < array + 10;pointer++){
        printf("%3d",*pointer);
    }
}

int fun(int *a,int n){
    int temp;
    int *p = a;
    int *q = a + n -1;
    for(;p<=a+(n-1)/2;p++,q--){
        temp = *p;
        *p = *q;
        *q = temp;
    }
}