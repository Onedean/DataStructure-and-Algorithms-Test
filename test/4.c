/* 
4.	36��ש��36�˰ᣬ�а�4��Ů��3������С��̧һש�����С�Ů��С���������ˣ�
 */

#include <stdio.h>
int main()
{
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 12; j++)
        {
            for (int k = 2; k <= 72; k = k + 2)
            {
                if (i * 4 + j * 3 + k / 2 == 36 && i + j + k == 36)
                {
                    printf("�У�%d,Ů��%d,С����%d", i, j, k);
                    return 0;
                }
            }
        }
    }
    return 0;
}