/*
 * @lc app=leetcode id=2367 lang=c
 *
 * [2367] Number of Arithmetic Triplets
 */

// @lc code=start
//Arrays
//number-of-arithmetic-triplets
//Time Complexity: O(n) where n is the size of nums. We are using three pointers to iterate through the array, and each pointer moves forward without going back, leading to O(n) time complexity.
//Space Complexity: O(1) since we are using only a constant amount of extra space to store the count of arithmetic triplets and the three pointers. We are not using any additional data structures that grow with the input size.
//Approach: We can use three pointers to iterate through the array. The first pointer (i) starts at the beginning of the array, the second pointer (j) starts at the next position after i, and the third pointer (k) starts at the next position after j. We check if the difference between nums[j] and nums[i] is equal  to diff, and if the difference between nums[k] and nums[j] is also equal to diff. If both conditions are satisfied, we increment the count of arithmetic triplets and move all three pointers forward. If the conditions are not satisfied, we move the first pointer (i) forward and adjust the other two pointers (j and k) accordingly to ensure they are always ahead of i. We continue this process until any of the pointers reach the end of the array. Finally, we return the total count of arithmetic triplets found in the array.
int arithmeticTriplets(int* nums, int numsSize, int diff) {

    int count=0;
    int i=0,j=1,k=2;
    while(i<numsSize&&j<numsSize&&k<numsSize)
    {
        while(j<numsSize&&nums[j]-nums[i]<diff)
        {
            j++;
        }
        if(j==numsSize)
        {
            break;
        }
        while(k<numsSize&&nums[k]-nums[j]<diff)
        {
            k++;
        }
        if(k==numsSize)
        {
            break;
        }
        if (nums[j] - nums[i] == diff &&
            nums[k] - nums[j] == diff) {
            count++;
            i++;
            if (j <= i) j = i + 1;
            if (k <= j) k = j + 1;
        }
        else {
            i++;
            if (j <= i) j = i + 1;
            if (k <= j) k = j + 1;
        }
    }
    return count;
    
}
// @lc code=end

