/*
 * @lc app=leetcode id=50 lang=c
 *
 * [50] Pow(x, n)
 */

// @lc code=start
//Math
//pow-x-n
//Time Complexity: O(log n) where n is the exponent. This is because we are halving the exponent in each step of the algorithm.
//Space Complexity: O(1) since we are using only a constant amount of extra space to store the result and intermediate variables.
//Approach: We can use the method of exponentiation by squaring to calculate x raised to the power n efficiently. If n is negative, we take the reciprocal of x and make n positive. We initialize the result to 1 and then repeatedly square x and halve n until n becomes zero. If n is odd at any point, we multiply the result by the current value of x. Finally, we return the result.
double myPow(double x, int n) {
    if (x == 1){return 1;}
    if (x == 0){return 0;}
    long double result = 1;
    long long longn = n;
    if (longn < 0){longn = -longn;x = 1/x;}
        while (longn > 0) {
        if (longn % 2 == 1) {
            result *= x;
        }
        x *= x;
        longn /= 2;
    }
    return result;
}
// @lc code=end

