#include <stdio.h>
#include <string.h>
int main()
{
    char ch[100];
    scanf("%s", &ch);
    if (strlen(ch) > 1)
    {
        printf("���������޷�ʶ��\n");
        return 0;
    }
    switch (ch[0])
    {
    case 'Y':
    case 'y':
        printf("��ѡ�����ͬ�⣡\n");
        break;
    case 'N':
    case 'n':
        printf("��ѡ����Ǿܾ���\n");
        break;
    default:
        printf("���������޷�ʶ��\n");
        break;
    }
    return 0;
}