/* 
    共用体类型
        定义：
            使用覆盖技术，用同一段内存但愿存放不同的类型的变量
        语法：
            1、先声明后定义：
            union Date{
                int i;
                char ch;
                float:f;
            };
            union Date a,b,c;
            2、边声明边定义：
            union Date{
                int i;
                char ch;
                float:f;
            }a,b,c;
        内存长度：
            等于最长的成员的长度，如上边最长的float型变量占4个字节，所以a,b,c各占4个字节
        引用方式：
            不能引用共同体变量，只能引用共同体变量中的成员
        注意：
            1、同一内存段可以用来存放好几种不同类型的成员，但在每一瞬间只能存放其中一个成员，而不是同时存放几个
                union Date{
                  int i;
                  char ch;
                  float f;
                }a;
                a.i = 97;
                printf("%d, a.i");  // 97
                printf("%c, a.i");  // 'a'
                printf("%f, a.i");  // 0.000000  这里浮点数怎么转换的？？？？
            2、可以对共用体变量初始化，但初始化表中只能有一个常量
                union Date{
                  int i;
                  char ch;
                  float:f;
                };
                union Date a = {1, 'a', 1.5};  // 错
                union Date a = {16};  // 对
                union Date a = {.ch = 'f'};  // 对，C99运行对指定的一个成员初始化
            3、初始化后每次重新赋值，都会覆盖掉之前的
            4、共用体变量的地址和它的各成员的地址都是同一地址
            5、不能对共用体变量名赋值，以及企图引用变量名来得到一个值
            6、C99允许同类型的共用体变量互相赋值
 */

#include<stdio.h>
int main(){
    //todo
}