//����һ���������ĺ꣬�ҳ��������еĴ��ߡ��ֱ��3��5��3+5��5-3���������ݸ�������֤��д�ĺ��Ƿ���ȷ��
#include <stdio.h>
#define MAX(m, n) (m > n ? m : n)
void main()
{
    int max = MAX(3+5,5-3);
    printf("max=%d", max);
}
