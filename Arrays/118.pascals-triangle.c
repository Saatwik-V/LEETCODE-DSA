/*
 * @lc app=leetcode id=118 lang=c
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
//Arrays
//pascal's-triangle
//Time Complexity: O(numRows^2)
//Space Complexity: O(numRows^2)
//Approach: We can use a nested loop to generate the Pascal's Triangle. The outer loop runs from 0 to numRows-1, and the inner loop runs from 0 to the current row index. We fill the first and last elements of each row with 1, and for the other elements, we calculate their values as the sum of the two elements directly above them in the previous row.
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    *returnSize = numRows;
    int** arr = (int**)malloc(numRows * sizeof(int*));
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));

    for (int i = 0; i < numRows; i++) {
        arr[i] = (int*)malloc((i + 1) * sizeof(int));
        (*returnColumnSizes)[i] = i + 1;
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i)
                arr[i][j] = 1;
            else
                arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
        }
    }
    return arr;
}
// @lc code=end

