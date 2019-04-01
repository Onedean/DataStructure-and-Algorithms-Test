/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// 暴力法：(事件复杂度O(n^n))
#include <stdio.h>
#define Array_Len(array) (sizeof(array) / sizeof(array[0]))
int *twoSum(int *nums, int numsSize, int target)
{
    static int result[2];
    for (int *i = nums; i < nums + numsSize - 1; i++)
    {
        for (int *j = i + 1; j < nums + numsSize; j++)
        {
            if (*i + *j == target)
            {
                result[0] = i - nums;
                result[1] = j - nums;
                return result;
            }
        }
    }
    return NULL;
}

int main()
{
    int nums[] = {2, 7, 11, 15, 2, 7}, numsSize = Array_Len(nums), target = 9;
    int *p = twoSum(nums, numsSize, target);
    if (p != NULL)
    {
        printf("%d,%d\n", p[0], p[1]);
    }
    return 0;
}