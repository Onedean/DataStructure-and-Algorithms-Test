//ͨ��ָ������������ͱ���

#include <stdio.h>
int main()
{
    int a = 100, b = 10;
    int *pointer_1, *pointer_2;
    pointer_1 = &a; // pointer��ָ���������  // ��ֵΪ����a�ĵ�ַ��*pointerָ�����a�ĵ�ַ
    pointer_2 = &b;
    printf("the value a = %d, the value b = %d\n", a, b);
    printf("the pointer a = %d, the pointer b = %d\n", *pointer_1, *pointer_2);
    /* pointer_1 = a;  // ���������Ǵ�ģ���ָ�������ֵ������a��ֵ��*pointerָ��ĵ�ַΪ����aֵ�ĵ�ַ��δ֪�ᱨ��
    pointer_2 = b;
    printf("the pointer a = %d, the pointer b = %d\n",* pointer_1,* pointer_2); */
    return 0;
}