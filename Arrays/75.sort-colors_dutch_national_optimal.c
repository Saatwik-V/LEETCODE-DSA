/*
 * @lc app=leetcode id=75 lang=c
 *
 * [75] Sort Colors
 */

// @lc code=start
//Arrays
//sort-colors
//Time Complexity: O(n) where n is the length of the input array. We traverse the array once.
//Space Complexity: O(1) since we are using only a constant amount of extra space to store intermediate variables and perform swaps.
//Approach: We can use the Dutch National Flag algorithm to sort the colors in place. We initialize three pointers: low, mid, and high. The low pointer keeps track of the position where the next 0 should be placed, the mid pointer is used to traverse the array, and the high pointer keeps track of the position where the next 2 should be placed. We iterate through the array with the mid pointer. If we encounter a 0, we swap it with the element at the low pointer and move both low and mid pointers forward. If we encounter a 1, we simply move the mid pointer forward. If we encounter a 2, we swap it with the element at the high pointer and move the high pointer backward. We continue this process until the mid pointer exceeds the high pointer, at which point the array will be sorted in place. Finally, we return from the function since the sorting is done in place.
void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
    return;
}

void sortColors(int* nums, int numsSize) {
   int low=0, mid=0,high=numsSize-1;
   while(mid<=high)
   {
     if(nums[mid]==0)
     {
        swap(&nums[mid],&nums[low]);
        mid+=1;
        low+=1;
     }
     else if(nums[mid]==1)
     {
        mid+=1;
     }
     else{
        swap(&nums[mid],&nums[high]);
        {
            high-=1;
        }
     }
   }
   return;
}
// @lc code=end

