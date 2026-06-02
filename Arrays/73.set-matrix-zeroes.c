/*
 * @lc app=leetcode id=73 lang=c
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
//Arrays
//set-matrix-zeroes
//Time Complexity: O(m*n) where m is the number of rows and n is the number of columns in the matrix.
//Space Complexity: O(1) since we are using only a constant amount of extra space to store the flags for the first row and first column.
//Approach: We can use the first row and first column of the matrix to store the information about which rows and columns should be set to zero. We first check if the first row and first column contain any zeros and set flags accordingly. Then, we iterate through the rest of the matrix and mark the first row and first column for any zeros found. Finally, we iterate through the matrix again and set the elements to zero based on the markings in the first row and first column. If the flags for the first row and first column are set, we also set the entire first row and first column to zero.      

#include <stdbool.h>
void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int rows = matrixSize;
    int cols = matrixColSize[0]; 
    bool firstRowZero = false;
    bool firstColZero = false;
    for (int j = 0; j < cols; j++) {
        if (matrix[0][j] == 0) {
            firstRowZero = true;
            break;
        }
    }
    for (int i = 0; i < rows; i++) {
        if (matrix[i][0] == 0) {
            firstColZero = true;
            break;
        }
    }
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }
    if (firstRowZero) {
        for (int j = 0; j < cols; j++) {
            matrix[0][j] = 0;
        }
    }
    if (firstColZero) {
        for (int i = 0; i < rows; i++) {
            matrix[i][0] = 0;
        }
    }
}
// @lc code=end

