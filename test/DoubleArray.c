#include<stdio.h>
int main(){
    int a[3][4] = {1,3,5,7,9,11,13,15,17,19,21,23};
    int (*p)[4],i,j;  // ����һά�����ָ�����
    //int *p,i,j;
    p = a;  // ָ������ĵ�0��
    printf("please input row and colum:");
    scanf("%d,%d",&i,&j);
    printf("a[%d,%d]=%d\n",i,j,*(*(p+i)+j));  // ǰ��һά�������ֽڳ��ȣ����һά��������ֽڳ���
    //printf("a[%d,%d]=%d\n",i,j,*(p+i));
    return 0;
}