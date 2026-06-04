/*
 * @lc app=leetcode id=912 lang=c
 *
 * [912] Sort an Array
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//Arrays
//sort-an-array
//Time Complexity: O(n log n) where n is the length of the input array. This is because we are using the merge sort algorithm, which has a time complexity of O(n log n).       
//Space Complexity: O(n) since we are using an auxiliary array to store the merged results during the merge step of the merge sort algorithm.
//Approach:QuickSort
 void swap(int *a,int *b)
 {
    int t=*a;
    *a=*b;
    *b=t;
    return;
 }
int lomuto(int *a,int l,int r,int numsSize)
{
    int p=a[l],s=l;
    for(int i=l+1;i<=r;i++)
    {
        if(a[i]<p)
        {
            s++;
            swap(&a[i],&a[s]);

        }
    }
    swap(&a[l],&a[s]);
    return s;

}
 
 void quicksort(int *a,int l,int r,int numsSize)
 {
    int s;
    if(l<r)
    {
        s=lomuto(a,l,r,numsSize);
        quicksort(a,l,s-1,numsSize);
        quicksort(a,s+1,r,numsSize);
        
    }
    return;
 }
int* sortArray(int* nums, int numsSize, int* returnSize) {

    *returnSize=numsSize;
    quicksort(nums,0,numsSize-1,numsSize);
    return nums;

}
// @lc code=end

