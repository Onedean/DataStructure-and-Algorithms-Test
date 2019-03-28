// ��ָ�����飩�����ɸ��ַ�������ĸ˳����С�������

#include <stdio.h>
#include <string.h>
int main()
{
    void sort(char *[], int);                                   // ����sort������
    void print(char *[], int);                                  // ����print��ӡ����
    char *name[] = {"one", "dean", "three", "four", "pointer"}; //����ָ�����飬ָ�������ַ�������,���Դ�Ÿ����ַ�����������ĸ�ĵ�ַ���൱�ڶ�����һ��ָ��ָ�����ݵ�ָ��
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", name + i); // ָ�������Ԫ�ش洢�����ַ�������������ĸ��ַ
    }
    printf("\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", *(name + i));  // �����ڴ��ַ����Ϊ���ַ����������ȼ�'\0'��1������
    }
    printf("\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%s ", *(name + i));
    }
    printf("\n");
    sort(name, 5);  // ����ָ���������ֵ��Ϊʵ�Σ�����������
    print(name, 5); // ����ָ���������ֵ��Ϊʵ�Σ�����������
    return 0;
}

void sort(char *name[], int n)
{
    char *temp;
    /* �±귨��
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(name[i], name[j]) > 0)
            {
                temp = name[i];
                name[i] = name[j];
                name[j] = temp;
            }
        }
    } */
    // ָ�뷨��
    for (char **i = name; i < name + n - 1; i++)
    {
        for (char **j = i + 1; j < name + n; j++)
        {
            if (strcmp(*i, *j) > 0)
            {
                temp = *i;
                *i = *j;
                *j = temp;
            }
        }
    }
}

void print(char *name[], int n)
{
    /* �±귨��
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", name[i]);
    } */
    // ָ�뷨��
    for (char **i = name; i < name + n; i++)
    {
        printf("%s ", *i);
    }
}