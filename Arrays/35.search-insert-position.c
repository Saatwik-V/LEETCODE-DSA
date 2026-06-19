/*
 * @lc app=leetcode id=35 lang=c
 *
 * [35] Search Insert Position
 */

// @lc code=start
//arrays
//search-insert-position
//Time Complexity: O(log n) where n is the number of elements in the input array. This is because we are using binary search to find the target or the position to insert it, which has a logarithmic time complexity.
//Space Complexity: O(1) since we are using a constant amount of extra space for the variables low, high, and mid, regardless of the size of the input array.
//Approach: We can use binary search to find the target or the position to insert it. We initialize two pointers, low and high, to the start and end of the array, respectively. We then calculate the mid index and compare the value at mid with the target. If the value at mid is equal to the target, we return mid. If the value at mid is less than the target, we move the low pointer to mid + 1. If the value at mid is greater than the target, we move the high pointer to mid - 1. We continue this process until low is greater than high. At this point, low will be the index where the
int searchInsert(int* nums, int numsSize, int target) {
    int low=0;
    int high=numsSize-1;    
    int mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(nums[mid]==target)
        {
            return mid;
        }
        else if(nums[mid]<target)
        {
            low=mid+1;
        }
        else{high=mid-1;}

    }

    return low;
}
// @lc code=end

