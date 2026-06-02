/*
 * @lc app=leetcode id=231 lang=c
 *
 * [231] Power of Two
 */

// @lc code=start
//Math
//power-of-two
//Time Complexity: O(1) since we are performing a constant number of operations.
//Space Complexity: O(1) since we are using only a constant amount of extra space to store the result and intermediate variables.
//Approach: A number that is a power of two has exactly one bit set in its binary representation. Therefore, we can check if n is greater than 0 and if n & (n - 1) is equal to 0. If both conditions are true, then n is a power of two; otherwise, it is not. This works because n & (n - 1) will clear the least significant bit of n, and if n is a power of two, it will result in 0. If n is not a power of two, it will have more than one bit set, and n & (n - 1) will not be 0. Additionally, we need to check if n is greater than 0 because negative numbers and zero cannot be powers of two.
#include <stdbool.h>
bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}
// @lc code=end

