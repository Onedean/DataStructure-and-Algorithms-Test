/* 
    给定一个整数数组 nums，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 */

#include <stdio.h>
#define len 9
// 方法一：暴力法，时间复杂度O(n^3)
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

// 方法二：改进暴力法，时间复杂度O(n^2)
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

// 方法三：递归分而治之法,时间复杂度O(n*log(n))
// todo


//方法四：在线更新法，时间复杂度O(n)
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