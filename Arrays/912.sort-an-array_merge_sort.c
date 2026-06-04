/*
 * @lc app=leetcode id=912 lang=c
 *
 * [912] Sort an Array
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//Arrays
//sort-an-array
//Time Complexity: O(n log n) where n is the length of the input array. This is because we are using the merge sort algorithm, which has a time complexity of O(n log n).
//Space Complexity: O(n) since we are using an auxiliary array to store the merged results during the merge step of the merge sort algorithm.
//Approach: We can use the merge sort algorithm to sort the input array. The merge sort algorithm works by recursively dividing the array into two halves until we reach arrays of size one or zero, which are inherently sorted. We then merge the sorted halves back together in a sorted manner. The merge step involves comparing the elements of the two halves and building a new sorted array by selecting the smaller element from the two halves at each step. Finally, we return the sorted array as the result.
#include <stdlib.h>
 void merge(int *a,int l,int m,int r,int numsSize)
 {
    int* c=(int*)malloc((numsSize)*sizeof(int));
    int i=l,k=l,j=m+1;
    while(i<=m&&j<=r)
    {
        if(a[i]<a[j])
        {
            c[k]=a[i];
            i+=1;
        }
        else{
            c[k]=a[j];
            j+=1;
        }
        k+=1;
    }
    if(i>m)
    {
        while(j<=r)
        {
            c[k]=a[j];
            j+=1;
            k+=1;
        }
    }
    else{
        while(i<=m)
        {
            c[k]=a[i];
            i+=1;
            k+=1;
        }
    }
    for(int i=l;i<=r;i++)
    {
        a[i]=c[i];
    }
    return;
 }

 void mergesort(int *a,int l,int r,int numsSize)
 {
    int m;
    if(l<r)
    {
        m=floor((l+r)/2);
        mergesort(a,l,m,numsSize);
        mergesort(a,m+1,r,numsSize);
        merge(a,l,m,r,numsSize);
    }
    return;
 }
int* sortArray(int* nums, int numsSize, int* returnSize) {

    *returnSize=numsSize;
    mergesort(nums,0,numsSize-1,numsSize);
    return nums;
}
// @lc code=end

