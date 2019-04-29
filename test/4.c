/* 
4.	36块砖，36人搬，男搬4，女搬3，两个小孩抬一砖，问男、女和小孩各多少人？
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
                    printf("男：%d,女：%d,小孩：%d", i, j, k);
                    return 0;
                }
            }
        }
    }
    return 0;
}