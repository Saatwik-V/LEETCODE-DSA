/*
 * @lc app=leetcode id=2574 lang=c
 *
 * [2574] Left and Right Sum Differences
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//Arrays
//left-and-right-sum-differences
//Time Complexity: O(n^2) where n is the length of the input array. This is because we have two nested loops: the outer loop iterates through each element of the array, and the inner loops calculate the left sum and right sum for each element.
//Space Complexity: O(n) since we are using three additional arrays of size n to store the left sums, right sums, and the result.
 //Approach: We can iterate through each element of the input array and calculate the left sum and right sum for that element. The left sum is the sum of all elements to the left of the current element, and the right sum is the sum of all elements to the right of the current element. We can use two nested loops to calculate the left sum and right sum for each element. We then calculate the absolute difference between the left sum and right sum and store it in the result array. Finally, we return the result array containing the left and right sum differences for each element in the input array.
#include <stdio.h>
#include <stdlib.h>

int* leftRightDifference(int* nums, int numsSize, int* returnSize) {
    *returnSize=numsSize;
    int *leftSum=(int*)malloc(numsSize*sizeof(int));
    int *rightSum=(int*)malloc(numsSize*sizeof(int));
    int *res=(int*)malloc(numsSize*sizeof(int));
    for(int i=0;i<numsSize;i++)
    {
        res[i]=0;
        leftSum[i]=0;
        for(int j=0;j<i;j++)
        {
            leftSum[i]+=nums[j];
        }
        rightSum[i]=0;
        for(int j=i+1;j<numsSize;j++)
        {
            rightSum[i]+=nums[j];
        }
        res[i]=abs(leftSum[i]-rightSum[i]);
    }
    return res;
    
}
// @lc code=end

