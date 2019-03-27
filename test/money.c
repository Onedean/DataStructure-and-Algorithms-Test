#include<stdio.h>
#include<math.h>
int main(){
    float money,rate,sum;
    int year;
    scanf("%f %d %f",&money,&year,&rate);
    sum = money * pow(1 + rate,year);
    printf("sum=%.2f",sum);
    return 0;
}
