/*
    д��������������ʽ�ڸ�����x����ֵ��
        ��һ��f(x) = a(0) + a(1) * x + ... + a(n-1) * x ^ (n-1) + a(n) * x ^ n
        ������f(x) = a(0) + x * ( a(1) + x * (... x * (a(n-1) + x * a(n) ) ) )
*/

#include <stdio.h>
#include <math.h>
#include <time.h>
#define MAXK 1e7 //���⺯������ظ����ô���
#define MAXN 10  // ����ʽ���������������ʽ�����ӳ�����1��

clock_t start, stop; // ���忪ʼ�ͽ�������ʱ�Ӵ�����ͱ���
double duration;     // ��������Ϊ��λ����¼�����Ժ�������ʱ��

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
    start = clock(); // ��ʼ��ʱ
    double temp;
    for (int i = 0; i < MAXK; i++)
    {
        temp = (*p)(MAXN - 1, a, num); // ִ�в��Ժ���
    }
    printf("%8.3lf\n",temp);
    stop = clock();                                       // ֹͣ��ʱ
    duration = ((double)(stop - start)) / CLK_TCK / MAXK; // CLK_TCK�ǻ���ÿ�����ߵ�ʱ�Ӵ��������������ʱ��
    printf("ticks = %f\n", (double)(stop - start));
    printf("duration = %6.2e\n", duration);
}

int main()
{
    double a[MAXN];
    double num;
    double (*p)(int, double[], double); // ���庯��ָ�����
    scanf("%lf", &num);
    for (int i = 0; i < MAXN; i++)
    {
        a[i] = (double)i;
    }
    testClock(f1, a, num);
    testClock(f2, a, num);
    return 0;
}