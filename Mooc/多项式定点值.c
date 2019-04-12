/*
    写程序计算给定多项式在给定点x处的值：
        法一：f(x) = a(0) + a(1) * x + ... + a(n-1) * x ^ (n-1) + a(n) * x ^ n
        法二：f(x) = a(0) + x * ( a(1) + x * (... x * (a(n-1) + x * a(n) ) ) )
*/

#include <stdio.h>
#include <math.h>
#include <time.h>
#define MAXK 1e7 //被测函数最大重复调用次数
#define MAXN 10  // 多项式最大项数，即多项式阶数加常数项1项

clock_t start, stop; // 定义开始和结束两个时钟打点类型变量
double duration;     // 定义以秒为单位，记录被测试函数运行时间

double f1(int n, double a[], double x)
{
    double p = a[0];
    for (int i = 1; i <= n; i++)
    {
        p += (a[i] * pow(x, i));
    }
    return p;
}

double f2(int n, double a[], double x)
{
    double p = a[n];
    for (int i = n; i > 0; i--)
    {
        p = a[i - 1] + x * p;
    }
    return p;
}

void testClock(double (*p)(int, double[], double), double *a, double num)
{
    start = clock(); // 开始计时
    double temp;
    for (int i = 0; i < MAXK; i++)
    {
        temp = (*p)(MAXN - 1, a, num); // 执行测试函数
    }
    printf("%8.3lf\n",temp);
    stop = clock();                                       // 停止计时
    duration = ((double)(stop - start)) / CLK_TCK / MAXK; // CLK_TCK是机器每秒所走的时钟打点数，计算运行时间
    printf("ticks = %f\n", (double)(stop - start));
    printf("duration = %6.2e\n", duration);
}

int main()
{
    double a[MAXN];
    double num;
    double (*p)(int, double[], double); // 定义函数指针变量
    scanf("%lf", &num);
    for (int i = 0; i < MAXN; i++)
    {
        a[i] = (double)i;
    }
    testClock(f1, a, num);
    testClock(f2, a, num);
    return 0;
}