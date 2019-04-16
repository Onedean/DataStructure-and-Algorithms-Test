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

// 方法三：递归分而治之法,时间复杂度O(n*log(n))    //todo自己再敲一遍
int max(int a, int b, int c)
{ /* 返回3个整数中的最大值 */
    return a > b ? a > c ? a : c : b > c ? b : c;
}

int DivideAndConquer(int List[], int left, int right)
{                                            /* 分治法求List[left]到List[right]的最大子列和 */
    int MaxLeftSum, MaxRightSum;             /* 存放左右子问题的解 */
    int MaxLeftBorderSum, MaxRightBorderSum; /*存放跨分界线的结果*/

    int LeftBorderSum, RightBorderSum;
    int center, i;

    if (left == right)
    { /* 递归的终止条件，子列只有1个数字 */
        if (List[left] > 0)
            return List[left];
        else
            return 0;
    }

    /* 下面是"分"的过程 */
    center = (left + right) / 2; /* 找到中分点 */
    /* 递归求得两边子列的最大和 */
    MaxLeftSum = DivideAndConquer(List, left, center);
    MaxRightSum = DivideAndConquer(List, center + 1, right);

    /* 下面求跨分界线的最大子列和 */
    MaxLeftBorderSum = 0;
    LeftBorderSum = 0;
    for (i = center; i >= left; i--)
    { /* 从中线向左扫描 */
        LeftBorderSum += List[i];
        if (LeftBorderSum > MaxLeftBorderSum)
            MaxLeftBorderSum = LeftBorderSum;
    } /* 左边扫描结束 */

    MaxRightBorderSum = 0;
    RightBorderSum = 0;
    for (i = center + 1; i <= right; i++)
    { /* 从中线向右扫描 */
        RightBorderSum += List[i];
        if (RightBorderSum > MaxRightBorderSum)
            MaxRightBorderSum = RightBorderSum;
    } /* 右边扫描结束 */

    /* 下面返回"治"的结果 */
    return max(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}

int maxSubseqSum3(int List[], int N)
{ /* 保持与前2种算法相同的函数接口 */
    return DivideAndConquer(List, 0, N - 1);
}

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