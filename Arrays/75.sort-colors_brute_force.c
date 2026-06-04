/*
 * @lc app=leetcode id=75 lang=c
 *
 * [75] Sort Colors
 */

// @lc code=start
//Arrays
//sort-colors
//Time Complexity: O(n) where n is the length of the input array. We traverse the array twice: once to count the occurrences of each color and once to overwrite the original array with the sorted colors.
//Space Complexity: O(1) since we are using only a constant amount of extra space to store the counts of each color and intermediate variables.
//Approach: We can use a counting sort approach to sort the colors in place. We initialize three counters, c0, c1, and c2, to count the occurrences of 0s, 1s, and 2s in the input array. We then traverse the array once to populate these counters. After counting the occurrences of each color, we overwrite the original array with the sorted colors based on the counts. We first fill in c0 number of 0s, then c1 number of 1s, and finally c2 number of 2s. This way, we sort the colors in place without using any additional data structures. Finally, we return from the function since the sorting is done in place.
#include <stdio.h>
void sortColors(int* nums, int numsSize) {
    int c0=0,c1=0,c2=0;
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]==0)
        {
            c0++;
        }
        else if(nums[i]==1)
        {
            c1++;
        }
        else{
            c2++;
        }
    }
    
    for(int i=0;i<c0;i++)
    {
        nums[i]=0;
    }
    for(int i=c0;i<(c0+c1);i++)
    {
        nums[i]=1;
    }
    for(int i=(c0+c1);i<numsSize;i++)
    {
        nums[i]=2;
    }

    return;
}
// @lc code=end

