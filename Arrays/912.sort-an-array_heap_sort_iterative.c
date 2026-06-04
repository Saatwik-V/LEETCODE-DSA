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
//Time Complexity: O(n log n) where n is the length of the input array.     
//Space Complexity: O(1) since we are sorting the array in place and using only a constant amount of extra space to store intermediate variables.   
//Approach: We can use the heap sort algorithm to sort the input array. The heap sort algorithm works by first building a max heap from the input array. We can do this by calling the heapify function on each non-leaf node starting from the last non-leaf node down to the root node. Once we have a max heap, we can repeatedly swap the root of the heap (the largest element) with the last element of the heap and then call heapify on the reduced heap to maintain the max heap property. We continue this process until we have sorted the entire array. Finally, we return the sorted array as the result.  
 #include <stdbool.h>   
void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

void heap_bottomup(int *h,int n)
{
    for(int i=(n-1)/2;i>=0;i--)
    {
        int k=i,j;
        int v=h[k];
        bool heap=false;

        while(!heap && (2*k+1)<=n)
        {
            j=2*k+1;

            if(j<n && h[j]<h[j+1])
                j+=1;

            if(v>=h[j])
                heap=true;
            else{
                h[k]=h[j];
                k=j;
            }
        }
        h[k]=v;
    }
}

void heapify(int *h,int n)
{
    int k=0,j;
    int v=h[k];
    bool heap=false;

    while(!heap && (2*k+1)<=n)
    {
        j=2*k+1;

        if(j<n && h[j]<h[j+1])
            j+=1;

        if(v>=h[j])
            heap=true;
        else{
            h[k]=h[j];
            k=j;
        }
    }

    h[k]=v;
}

void heapsort(int *h,int n)
{
    heap_bottomup(h,n);

    for(int i=n;i>=1;i--)
    {
        swap(&h[i],&h[0]);
        heapify(h,i-1);
    }
}

int* sortArray(int* nums, int numsSize, int* returnSize)
{
    *returnSize = numsSize;

    heapsort(nums, numsSize-1);
    int* res = (int*)malloc(numsSize * sizeof(int));
    memcpy(res, nums, numsSize * sizeof(int));

    return res;
}
// @lc code=end

