/*
 * @lc app=leetcode id=53 lang=c
 *
 * [53] Maximum Subarray
 */

// @lc code=start
//Arrays
//maximum-subarray
//Time Complexity: O(n^2) where n is the length of the input array. This is because we have two nested loops: the outer loop iterates through each element of the array, and the inner loop calculates the sum of the subarray starting from the current element to the end of the array.
//Space Complexity: O(1) since we are using only a constant amount of extra space to store the result and intermediate variables.
//Approach: We can use a brute-force approach to find the maximum subarray sum. We initialize a variable result to the smallest possible integer value (INT_MIN) to keep track of the maximum sum found so far. We then use two nested loops: the outer loop iterates through each element of the array, and the inner loop calculates the sum of the subarray starting from the current element to the end of the array. We update the result variable if we find a sum that is greater than the current result. Finally, we return the result as the maximum subarray sum.
#include <limits.h>
int maxSubArray(int* nums, int numsSize) {
    
    int result=INT_MIN;
    for(int i=0;i<numsSize;i++)
    {
        int sum=0;
        for (int j=i;j<numsSize;j++)
        {
            sum+=nums[j];
            if(sum>result)
            {
                result=sum;
            }
        }
    }
    return result;
}
// @lc code=end

