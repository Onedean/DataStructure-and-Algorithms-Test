//������ָ��ֵ�ĺ���������ѧ�����йҿƵ�ѧ���ż���ȫ���ɼ�

#include <stdio.h>
int main()
{
    float score[][4] = {{60, 70, 80, 90}, {56, 89, 67, 88}, {34, 78, 90, 66}};
    float *search(float(*)[], int); // ��������ָ��ֵ���͵ĺ���
    float *p;
    for (int i = 0; i < 3; i++)
    {
        p = search(score + i, 4); // ���÷���ָ�����ͺ������ظ�һ��ָ�����
        if (p == *(score + i))    // ���ָ�����������Ӧ���ص���ָ��
        {
            printf("no.%d falied student:", i + 1);
            for (int j = 0; j < 4; j++)
            {
                printf("%8.2f", *(p + j));
            }
            printf("\n");
        }
    }

    return 0;
}

float *search(float (*p)[4], int n)
{
    float *pointer = NULL; // ��ʼ��ָ��ֵ
    for (int i = 0; i < n; i++)
    {
        if (*(*p + i) < 60)
        {
            pointer = *p; // ָ���������ָ����ָ��
        }
    }
    return pointer; // ����ָ��ֵ

    /* д������ָ�뷨
    float *y = NULL;
    for (float *x = *p; x < *p + n; x++)
    {
        if (*x < 60)
        {
            y = *p;
        }
    }
    return y; */
}
