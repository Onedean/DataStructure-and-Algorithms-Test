// һ����3��ѧ������4�ſΣ�������ָ��������βεĺ���������ƽ���ֺ������3��ѧ���ĳɼ�

#include <stdio.h>
int main()
{
    void average(float *, int);
    void search(float(*)[], int);
    float arr[3][4] = {{65, 67, 70, 60}, {80, 87, 90, 81}, {90, 99, 100, 98}};
    average(*arr, 12); // ����ʵ��*arr��ָ�������0��0�е���ָ��
    search(arr, 2);    // ����ʵ��arr��ָ�������0�е���ָ��
    return 0;
}

void average(float *p, int n) // �����β�����ָ�������ָ������������β�
{
    float sum = 0;
    for (float *q = p; q < p + n; q++) // ע�����ﲻ�� q < *p +n����Ϊp=*arr����ָ���е�ָ��
    {
        sum = sum + *q;
    }
    printf("the average score is %.2f\n", sum / n);
}

void search(float (*p)[4], int n)
{ // �����β�����ָ��һά�����ָ������������β�
    printf("the score of no.%d are:");
    for (int i = 0; i < 4; i++)
    {
        printf("%5.2f ", *(*(p + n) + i)); // ע������ p + n ÿ�μӵ������ֽڳ���
    }
}