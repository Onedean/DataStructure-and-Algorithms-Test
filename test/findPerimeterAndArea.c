#include<stdio.h>
#define PI 3.1415
int main(){
    void Perimeter(float,float);
    void Area(float);
    float a,b;
    int flag;
    printf("���������(1)����Բ(2):");
    scanf("%d",&flag);
    if(flag==1){
        do
        {
            printf("input=");
            scanf("%f %f",&a,&b);
        } while (a<0 || b<0); /*�ж��Ƿ��������*/
        Perimeter(a,b);
    }else if(flag==2){
        do
        {
            printf("input=");
            scanf("%f",&a);
        } while (a<0);
        Area(a);
    };
    return 0;
}
void Perimeter(float a,float b){
    printf("output=\n");
    printf("�ܳ�=%f,���=%f",2*(a+b),a*b);
}
void Area(float a){
    printf("output=\n");
    printf("�ܳ�=%f,���=%f",2*PI*a,PI*a*a);
}