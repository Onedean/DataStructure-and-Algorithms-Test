// ���ַ���a����Ϊ�ַ���b��Ȼ�����b

#include <stdio.h>
int main()
{
    // ���鷨��
    char a[] = "test for copy string by index", b[20];
    int i;
    for (i = 0; *(a + i) != '\0'; i++)
    {
        *(b + i) = *(a + i);
    }
    *(b + i) = '\0';
    printf("string a is: %s\n", a); // ��������ַ���a
    printf("string b is: ");
    for (int i = 0; *(b + i) != '\0'; i++)
    {
        printf("%c", *(b + i));
    }
    printf("\n");

    // ָ�뷨��
    char x[] = "test for copy string by pure pointer", y[40];
    char *p1 = x, *p2 = y;
    for (; *p1 != '\0'; p1++, p2++)
    {
        *p2 = *p1;
    }
    *p2 = '\0';
    printf("string x is: %s\n", x); // ע��������������ַ�����x��y���������ַ�ָ��p1��p2
    printf("string y is: %s\n", y);
    printf("*p1 = %c , *p2 = %c\n", *(p1 - 1), *(p2 - 1)); // �ַ�ָ��p1��p2��ʱ�Ѿ�ָ������ַ���������'\0'��ַ��
    return 0;
}