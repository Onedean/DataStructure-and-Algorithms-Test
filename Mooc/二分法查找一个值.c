/* 
    给定N个从小到大排好序的整数序列List[]，以及某待查找整数X，
    我们的目标是找到X在List中的下标。即若有List[i]=X，则返回i；否则返回-1表示没有找到。
    二分法是先找到序列的中点List[M]，与X进行比较，若相等则返回中点下标；否则，若List[M]>X，
    则在左边的子系列中查找X；若List[M]<X，则在右边的子系列中查找X。
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