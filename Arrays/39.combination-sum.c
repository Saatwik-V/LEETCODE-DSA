/*
 * @lc app=leetcode id=39 lang=c
 *
 * [39] Combination Sum
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
//Arrays
//combination-sum
//Time Complexity: O(k * n^k) where n is the number of candidates and k is the average length of the combinations. In the worst case, we may have to explore all possible combinations of candidates, which can lead to a time complexity of O(n^k). Additionally, we need to copy each valid combination to the result array, which takes O(k) time.
//Space Complexity: O(k) for the temporary array used to store the current combination, and O(m) for the result array where m is the number of valid combinations found. The space complexity can be considered O(m * k) in the worst case, as we may have m combinations each of length k.
 //Approach: We can use backtracking to explore all possible combinations of candidates that sum up to the target. We start with an empty combination and iterate through the candidates. For each candidate, we can either include it in the current combination and continue searching for the remaining target (target - candidate) or skip it and move to the next candidate. We also need to ensure that we do not exceed the target and that we can reuse the same candidate multiple times. When we find a valid combination that sums up to the target, we add it to the result array. We continue this process until we have explored all candidates and combinations. Finally, we return the result array containing all valid combinations.
#include <stdlib.h>

void backtrack(int* candidates, int candidatesSize, int target, 
               int start, int* temp, int tempSize,
               int*** result, int* returnSize, int** returnColumnSizes) {
    
    // If target achieved
    if(target == 0) {
        (*result)[*returnSize] = (int*)malloc(tempSize * sizeof(int));
        
        for(int i = 0; i < tempSize; i++) {
            (*result)[*returnSize][i] = temp[i];
        }
        
        (*returnColumnSizes)[*returnSize] = tempSize;
        (*returnSize)++;
        return;
    }

    for(int i = start; i < candidatesSize; i++) {
        
        if(candidates[i] > target) continue;

        temp[tempSize] = candidates[i];

        // Stay at i (reuse allowed)
        backtrack(candidates, candidatesSize, target - candidates[i],
                  i, temp, tempSize + 1,
                  result, returnSize, returnColumnSizes);
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, 
                     int* returnSize, int** returnColumnSizes) {

    int** result = (int**)malloc(150 * sizeof(int*)); // max 150 solutions
    *returnColumnSizes = (int*)malloc(150 * sizeof(int));
    *returnSize = 0;

    int temp[100]; // to store current combination

    backtrack(candidates, candidatesSize, target, 0,
              temp, 0, &result, returnSize, returnColumnSizes);

    return result;
}
// @lc code=end

