// �������ʹ�ú���ָ��������ú����������������������û�ѡ��1��2,1����max�������ֵ��2����min������Сֵ

#include <stdio.h>
int main()
{
    int max(int, int);  // ����max����
    int min(int, int);  // ����min����
    int (*p)(int, int); // ���庯��ָ�����
    int x, y, choose;
    printf("please input tow number:");
    scanf("%d,%d", &x, &y);
    printf("please input your choose 1(max) or 2(min):");
    scanf("%d", &choose);
    if (choose == 1)
    {
        p = max; // ʹ����ָ�����ָ��max����
        printf("max is ");
    }
    else if (choose == 2)
    {
        p = min; // ʹ����ָ�����ָ��min����
        printf("min is ");
    }
    printf("%d", (*p)(x, y)); // ���ú���ָ����������
    return 0;
}

int max(int x, int y)
{
    return x > y ? x : y;
}

int min(int x, int y)
{
    return x < y ? x : y;
}