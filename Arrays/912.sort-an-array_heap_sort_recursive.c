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
//Time Complexity: O(n log n) where n is the length of the input array. This is because we are using the heap sort algorithm, which has a time complexity of O(n log n).
//Space Complexity: O(1) since we are sorting the array in place and using only a constant amount of extra space to store intermediate variables.
//Approach: We can use the heap sort algorithm to sort the input array. The heap sort algorithm works by first building a max heap from the input array. We can do this by calling the heapify function on each non-leaf node starting from the last non-leaf node down to the root node. Once we have a max heap, we can repeatedly swap the root of the heap (the largest element) with the last element of the heap and then call heapify on the reduced heap to maintain the max heap property. We continue this process until we have sorted the entire array. Finally, we return the sorted array as the result.  
 #include <stdbool.h>

void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

void heapify(int *h, int n, int i)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left <= n && h[left] > h[largest])
        largest = left;

    if(right <= n && h[right] > h[largest])
        largest = right;

    if(largest != i)
    {
        swap(&h[i], &h[largest]);
        heapify(h, n, largest);
    }
}

void heap_bottomup(int *h, int n)
{
    for(int i = (n-1)/2; i >= 0; i--)
    {
        heapify(h, n, i);
    }
}

void heapsort(int *h, int n)
{
    heap_bottomup(h, n);

    for(int i = n; i > 0; i--)
    {
        swap(&h[0], &h[i]);
        heapify(h, i-1, 0);
    }
}

int* sortArray(int* nums, int numsSize, int* returnSize)
{
    *returnSize = numsSize;

    heapsort(nums, numsSize - 1);

    return nums;
}
// @lc code=end

