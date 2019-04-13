/* 
    ����N����С�����ź������������List[]���Լ�ĳ����������X��
    ���ǵ�Ŀ�����ҵ�X��List�е��±ꡣ������List[i]=X���򷵻�i�����򷵻�-1��ʾû���ҵ���
    ���ַ������ҵ����е��е�List[M]����X���бȽϣ�������򷵻��е��±ꣻ������List[M]>X��
    ������ߵ���ϵ���в���X����List[M]<X�������ұߵ���ϵ���в���X��
 */

#include <stdio.h>
#include <time.h>
#define LEN 10

int *sort(int *a)
{
    int temp;
    for (int i = 0; i < LEN - 1; i++)
    {
        for (int j = i + 1; j < LEN; j++)
        {
            if (*(a + i) > *(a + j))
            {
                temp = *(a + i);
                *(a + i) = *(a + j);
                *(a + j) = temp;
            }
        }
    }
    return a;
}

int find(int *a, int x)
{
    int left = 0, right = LEN - 1, middle = (left + right) / 2;
    while(a[middle] != x && left <= right){
        x < a[middle] ? (right = middle -1) : (left = middle +1);
        middle = (left + right) / 2;
    }
    return a[middle]==x ? middle : -1;
}

int main()
{
    int List[LEN] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int x;
    scanf("%d", &x);
    printf("%d\n", find(sort(List), x));
    return 0;
}