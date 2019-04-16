/* 
    ����һ���������� nums���ҵ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ������������͡�
 */

#include <stdio.h>
#define len 9
// ����һ����������ʱ�临�Ӷ�O(n^3)
int maxSubArray1(int *nums, int numsSize)
{
    int sum = 0;
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i; j < numsSize; j++)
        {
            int thisSum = 0;
            for (int k = i; k <= j; k++)
            {
                thisSum += nums[k];
            }
            if (thisSum > sum)
            {
                sum = thisSum;
            }
        }
    }
    return sum;
}

// ���������Ľ���������ʱ�临�Ӷ�O(n^2)
int maxSubArray2(int *nums, int numsSize)
{
    int sum = 0;
    for (int i = 0; i < numsSize; i++)
    {
        int thisSum = 0;
        for (int j = i; j < numsSize; j++)
        {
            thisSum += nums[j];
            if (thisSum > sum)
            {
                sum = thisSum;
            }
        }
    }
    return sum;
}

// ���������ݹ�ֶ���֮��,ʱ�临�Ӷ�O(n*log(n))    //todo�Լ�����һ��
int max(int a, int b, int c)
{ /* ����3�������е����ֵ */
    return a > b ? a > c ? a : c : b > c ? b : c;
}

int DivideAndConquer(int List[], int left, int right)
{                                            /* ���η���List[left]��List[right]��������к� */
    int MaxLeftSum, MaxRightSum;             /* �������������Ľ� */
    int MaxLeftBorderSum, MaxRightBorderSum; /*��ſ�ֽ��ߵĽ��*/

    int LeftBorderSum, RightBorderSum;
    int center, i;

    if (left == right)
    { /* �ݹ����ֹ����������ֻ��1������ */
        if (List[left] > 0)
            return List[left];
        else
            return 0;
    }

    /* ������"��"�Ĺ��� */
    center = (left + right) / 2; /* �ҵ��зֵ� */
    /* �ݹ�����������е����� */
    MaxLeftSum = DivideAndConquer(List, left, center);
    MaxRightSum = DivideAndConquer(List, center + 1, right);

    /* �������ֽ��ߵ�������к� */
    MaxLeftBorderSum = 0;
    LeftBorderSum = 0;
    for (i = center; i >= left; i--)
    { /* ����������ɨ�� */
        LeftBorderSum += List[i];
        if (LeftBorderSum > MaxLeftBorderSum)
            MaxLeftBorderSum = LeftBorderSum;
    } /* ���ɨ����� */

    MaxRightBorderSum = 0;
    RightBorderSum = 0;
    for (i = center + 1; i <= right; i++)
    { /* ����������ɨ�� */
        RightBorderSum += List[i];
        if (RightBorderSum > MaxRightBorderSum)
            MaxRightBorderSum = RightBorderSum;
    } /* �ұ�ɨ����� */

    /* ���淵��"��"�Ľ�� */
    return max(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}

int maxSubseqSum3(int List[], int N)
{ /* ������ǰ2���㷨��ͬ�ĺ����ӿ� */
    return DivideAndConquer(List, 0, N - 1);
}

//�����ģ����߸��·���ʱ�临�Ӷ�O(n)
int maxSubArray4(int *nums, int numsSize)
{
    int sum = 0, thisSum = 0, max = nums[0];
    for (int i = 0; i < numsSize; i++)
    {
        max = nums[i] > max ? nums[i] : max;
        thisSum += nums[i];
        if (thisSum > sum)
        {
            sum = thisSum;
        }
        else if (thisSum <= 0)
        {
            thisSum = 0;
        }
    }
    return max < 0 ? max : sum;
}

int main()
{
    int nums[len] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    printf("%d", maxSubArray4(nums, len));
    return 0;
}