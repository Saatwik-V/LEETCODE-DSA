/*
 * @lc app=leetcode id=1 lang=c
 *
 * [1] Two Sum
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//Arrays
//two-sum
//Brute Force
//Time Complexity: O(n^2)
//Space Complexity: O(1)
//Approach: We can use two nested loops to check every pair of numbers in the array. If the sum of any two numbers equals the target, we return their indices.
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *a;
    a=(int *)malloc(2*sizeof(int*));
    a[0]=0;
    a[1]=0;
    for(int i=0;i<numsSize;i++)
    {
        for(int j=i+1;j<numsSize;j++)
        {
            if(nums[i]+nums[j]==target)
            {
                *returnSize=2;
                a[0]=i;
                a[1]=j;
                return a;
            }
        }
    }
    int *b;
    return b;
    
}
// @lc code=end

