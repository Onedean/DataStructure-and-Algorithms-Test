//������������������Ӵ�С����������ú�������������ָ�����͵���������������

#include <stdio.h>
int main()
{
    void sort(int *, int *, int *);
    int t1, t2, t3;
    int *a = &t1, *b = &t2, *c = &t3; // д�������Ȱ����ͱ����ĵ�ַ��ָ���������ֱ�Ӹ�ָ�������ַ�洢�ռ��ֵ
    printf("please input tow number:");
    scanf("%d,%d,%d", a, b, c);
    /* scanf("%d,%d,%d",&t1,&t2,&t3);  // д��һ���ȸ����ͱ�����ַ�洢�ռ��ֵ���ڰѵ�ַ��ָ�����
    a = &t1;
    b = &t2;
    c = &t3; */
    printf("1---a = %d, b = %d, c = %d  &a = %d, &b = %d, &c = %d\n", *a, *b, *c, a, b, c);
    sort(a, b, c);
    printf("the order from big to small is %d, %d, %d\n", *a, *b, *c);
    return 0;
}

void sort(int *x, int *y, int *z)
{
    void swap(int *, int *);
    if (*x < *y)
    {
        swap(x, y);
        printf("1---x = %d, y = %d, z = %d  &x = %d, &y = %d, &z = %d\n", *x, *y, *z, x, y, z);
    }
    if (*x < *z)
    {
        swap(x, z);
        printf("2---x = %d, y = %d, z = %d  &x = %d, &y = %d, &z = %d\n", *x, *y, *z, x, y, z);
    }
    if (*y < *z)
    {
        swap(y, z);
        printf("3---x = %d, y = %d, z = %d  &x = %d, &y = %d, &z = %d\n", *x, *y, *z, x, y, z);
    }
}

void swap(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}