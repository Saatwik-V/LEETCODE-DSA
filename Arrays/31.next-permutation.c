/*
 * @lc app=leetcode id=31 lang=c
 *
 * [31] Next Permutation
 */

// @lc code=start
//Arrays
//next-permutation
//Time Complexity: O(n) where n is the length of the input array. We traverse the array a few times, but each traversal is linear in the size of the array.
//Space Complexity: O(1) since we are modifying the input array in place and using only a constant amount of extra space to store intermediate variables.
//Approach: We can find the next permutation by following these steps: First, we traverse the array from the end to find the first pair of indices (i, i+1) such that nums[i] < nums[i+1]. If no such pair is found, it means the array is in descending order, and we can simply reverse the entire array to get the lowest order (first permutation). If such a pair is found, we then traverse the array from the end again to find the first index j such that nums[j] > nums[i]. We swap the values at indices i and j, and then reverse the subarray from index i+1 to the end of the array to get the next permutation. Finally, we return the modified array as the result.
#include <stdio.h>
void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
void reverse(int *nums,int l,int r)
{
    while(l<r)
    {
        swap(&nums[l],&nums[r]);
        l++;
        r--;
    }
}

void nextPermutation(int* nums, int numsSize) {
    int n=numsSize-2;
    int index=-1;
    for(int i=n;i>=0;i--)
    {
        if(nums[i]<nums[i+1])
        {
            index=i;
            break;
        }
    }
    if(index==-1)
    {
        reverse(nums,0,numsSize-1);
        return;
    }
    else{
    for(int i=numsSize-1;i>index;i--)
    {
        if(nums[i]>nums[index])
        {
            swap(&nums[i],&nums[index]);
            break;
        }
    }
    }
    reverse(nums,index+1,numsSize-1);
}
// @lc code=end

