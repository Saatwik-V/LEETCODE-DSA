/*
 * @lc app=leetcode id=119 lang=c
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//Arrays
//pascal's-triangle-ii
//Time Complexity: O(k) where k is the rowIndex. We need to calculate the   values of the row up to rowIndex, which takes O(k) time.
//Space Complexity: O(k) since we are using an array of size k to store the values of the row.
//Approach: We can use the property of Pascal's triangle that each element is the sum of the two elements directly above it in the previous row. We can initialize an array of size rowIndex + 1 to store the values of the row. We set the first element of the array to 1 since the first element of every row in Pascal's triangle is 1. We then iterate through the row from the second element to the last element, calculating each element as the sum of the two elements directly above it in the previous row. We can use a variable to keep track of the previous value in the row to calculate the current value. Finally, we return the array containing the values of the row.      
#include <stdlib.h>
   
int* getRow(int rowIndex, int* returnSize) {
    *returnSize=rowIndex+1;
    long long n=rowIndex+1;
    long long ans=1;
    int *a=(int*)malloc(n*sizeof(int));
    a[0]=ans;
    for(int i=1;i<n;i++)
    {
        ans*=(n-i);
        ans=ans/i;
        a[i]=ans;
    }
    return a;
}
// @lc code=end

