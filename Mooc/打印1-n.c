// ��ӡ1-n��ȫ��������
#include<stdio.h>

// ������
void print1(int n){
    for(int i=1;i<=n;i++){
        printf("%d\n",i);
    }
    return;
}

//�ݹ鷨
void print2(int n){
    if(n){
        print2(n-1);
        printf("%d\n",n);
    }
    return;
}

int main(){
    int n;
    scanf("%d",&n);
    print1(n);
    print2(n);
    return 0;
}