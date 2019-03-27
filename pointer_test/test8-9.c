// 一个班3个学生，各4门课，用两个指针变量做形参的函数计算总平均分和输出第3个学生的成绩

#include <stdio.h>
int main()
{
    void average(float *, int);
    void search(float(*)[], int);
    float arr[3][4] = {{65, 67, 70, 60}, {80, 87, 90, 81}, {90, 99, 100, 98}};
    average(*arr, 12); // 这里实参*arr是指向数组第0行0列的列指针
    search(arr, 2);    // 这里实参arr是指向数组第0行的行指针
    return 0;
}

void average(float *p, int n) // 这里形参是用指向变量的指针变量来接收形参
{
    float sum = 0;
    for (float *q = p; q < p + n; q++) // 注意这里不是 q < *p +n，因为p=*arr，是指向列的指针
    {
        sum = sum + *q;
    }
    printf("the average score is %.2f\n", sum / n);
}

void search(float (*p)[4], int n)
{ // 这里形参是用指向一维数组的指针变量来接收形参
    printf("the score of no.%d are:");
    for (int i = 0; i < 4; i++)
    {
        printf("%5.2f ", *(*(p + n) + i)); // 注意这里 p + n 每次加的是行字节长度
    }
}