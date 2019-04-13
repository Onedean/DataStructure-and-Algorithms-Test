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

// ���������ݹ�ֶ���֮��,ʱ�临�Ӷ�O(n*log(n))
// todo


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