// �ú�������ʵ���ַ����ĸ��ƣ��ַ���ָ�������ʵ�κ��βΣ�

#include <stdio.h>
int main()
{
    void copy(char *, char *);
    char *a = "pratice for string pointer";
    char arr[] = "test string array for copy from a", *b = arr; // �ַ�ָ�����ָ���ַ�������ʱ�ַ������������ݲ����ٸ�ֵ���������ַ������е�����Ҫ�����ģ��������ַ�����洢
    printf("string a = %s\nstring b = %s\n", a, b);
    copy(a, b);
    printf("string a = %s\nstring b = %s\n", a, b);
    return 0;
}

void copy(char *a, char *b)
{
    // д��һ��
    /* while (*a != '\0')
    {
        *b = *a;
        a++;
        b++;
    } */

    // ��д�������ȸ�ֵ���ж�
    /* while ((*b = *a) != '\0')
    {
        a++;
        b++;
    } */

    // ��д�������ȸ�ֵ���ж�������
    /* while ((*b++ = *a++) != '\0')
    {
    } */

    //��д���ģ�'\0'ASCII����0ֱ���ж����
    while (*b++ = *a++)
    {
    }

    *b = '\0';
}