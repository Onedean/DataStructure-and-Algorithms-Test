#include <stdio.h>
#include <string.h>
void main()
{
    char sentence[3][50], high[3][1] = {0, 0, 0}, low[3][1] = {0, 0, 0}, num[3][1] = {0, 0, 0}, other[3][1] = {0, 0, 0};
    for (int i = 0; i < 3; i++)
    {
        scanf("%s", sentence[i]);
        for (int j = 0; j < strlen(sentence[i]); j++)
        {
            char letter = sentence[i][j];
            if (letter >= 'A' && letter <= 'Z')
                high[i][0] += 1;
            else if (letter >= 'a' && letter <= 'z')
                low[i][0] += 1;
            else if (letter >= '0' && letter <= '9')
                num[i][0] += 1;
            else
                other[i][0] += 1;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        printf("��%d������Ϊ��%s\n", i + 1, sentence[i]);
        printf("��д��ĸ����:%d\tСд��ĸ����:%d\t���ָ���:%d\t��������:%d\n", high[i][0], low[i][0], num[i][0], other[i][0]);
    }
}
