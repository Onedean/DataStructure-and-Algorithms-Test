// ��������е�ȫ��Ԫ��

#include <stdio.h>
int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // ����һ�������±귨
    for (int i = 0; i < 10; i++)
    {
        printf("%4d", a[i]);
    }
    printf("\n");

    // ��������ָ�뷨
    for (int i = 0; i < 10; i++)
    {
        printf("%4d", *(a + i));
    }
    printf("\n");

    // ��������ָ�뷨
    for (int i = 0, *p = a; i < 10; i++)
    {
        printf("%4d", *p++);
    }
    printf("\n");

    // �����ģ���ָ�뷨(ָ��ֱ��ָ���ַ���ٶ����)
    for (int *p = a; p < a + 10; p++)
    {
        printf("%4d", *p);
    }

    return 0;
}