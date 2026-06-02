/*
 * @lc app=leetcode id=29 lang=c
 *
 * [29] Divide Two Integers
 */

// @lc code=start
//Math
//divide-two-integers
//Time Complexity: O(1) since we are performing a constant number of operations.
//Space Complexity: O(1) since we are using only a constant amount of extra space to store the result and intermediate variables.
//Approach: We can simply use the division operator to divide the dividend by the divisor. However, we need to handle the edge case where the dividend is INT_MIN and the divisor is -1, as this would cause an overflow. In this case, we return INT_MAX. For all other cases, we can safely perform the division and return the result.
#include <limits.h>
int divide(int dividend, int divisor) {
    int c;
   if(dividend==-pow(2,31)&&divisor==-1)
   {
    c=INT_MAX;
   }
   else 
   c=dividend/divisor;
   return c;
}
// @lc code=end

