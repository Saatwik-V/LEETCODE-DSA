/*
 * @lc app=leetcode id=2367 lang=c
 *
 * [2367] Number of Arithmetic Triplets
 */

// @lc code=start
//Arrays
//number-of-arithmetic-triplets 
//Time Complexity: O(n^3) where n is the size of nums. We have three nested loops to iterate through all possible triplets in the array, leading to O(n^3) time complexity.
//Space Complexity: O(1) since we are using only a constant amount of extra space to store the count of arithmetic triplets. We are not using any additional data structures that grow with the input size.
//Approach: We can use three nested loops to iterate through all possible triplets  in the array. For each triplet (nums[i], nums[j], nums[k]), we check if the difference between nums[j] and nums[i] is equal to diff, and if the difference between nums[k] and nums[j] is also equal to diff. If both conditions are satisfied, we increment the count of arithmetic triplets. Finally, we return the total count of arithmetic triplets found in the array.    

int arithmeticTriplets(int* nums, int numsSize, int diff) {
    int count=0;
    for(int i=0;i<numsSize;i++)
    {
        for(int j=i+1;j<numsSize;j++)
        {
            if(nums[j]-nums[i]==diff)
            {
                for(int k=j+1;k<numsSize;k++)
                {
                    if(nums[k]-nums[j]==diff)
                    {
                        count++;
                    }
                }
            }
        }
    }
    return count;
}
// @lc code=end

