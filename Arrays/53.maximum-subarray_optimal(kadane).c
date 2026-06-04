/*
 * @lc app=leetcode id=53 lang=c
 *
 * [53] Maximum Subarray
 */

// @lc code=start
//Arrays
//maximum-subarray
//Time Complexity: O(n) where n is the length of the input array. We traverse the array once.
//Space Complexity: O(1) since we are using only a constant amount of extra space to store the result and intermediate variables.
//Approach: We can use Kadane's algorithm to find the maximum subarray sum efficiently. We initialize a variable result to the smallest possible integer value (INT_MIN) to keep track of the maximum sum found so far, and a variable sum to 0 to keep track of the current subarray sum. We then iterate through the array, adding each element to sum. If sum is greater than result, we update result with the value of sum. If sum becomes negative at any point, we reset it to 0 since a negative sum would not contribute to a maximum sum in the future. Finally, we return result as the maximum subarray sum.
#include <limits.h>
int maxSubArray(int* nums, int numsSize) {
    
    int result=INT_MIN;
    int sum=0;
    for(int i=0;i<numsSize;i++)
    {
        sum+=nums[i];
        if(sum>result)
        {
            result=sum;
        }
        if(sum<0)
        {
            sum=0;
        }
    }
    return result;
}
// @lc code=end

