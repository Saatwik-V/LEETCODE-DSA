/*
 * @lc app=leetcode id=7 lang=c
 *
 * [7] Reverse Integer
 */

// @lc code=start
#include <limits.h>
//Math
//reverse-integer
//Time Complexity: O(log10(n)) where n is the input integer. This is because we are processing each digit of the integer once.
//Space Complexity: O(1) since we are using only a constant amount of extra space to store the result and intermediate variables.
//Approach: We can use a while loop to reverse the digits of the integer. We extract the last digit of the integer using the modulus operator and add it to the reversed number after multiplying the reversed number by 10. We then remove the last digit from the original integer by dividing it by 10. We also need to check for overflow and underflow conditions before updating the reversed number. If the reversed number exceeds the range of a 32-bit signed integer, we return 0. Finally, we return the reversed number.
int reverse(int x){
    long int rev=0;
    int temp,c=x;
    while (x!=0)
    {
        temp=x%10;
        rev=rev*10+temp;
        x=x/10;
    }
    if(c==0||rev>INT_MAX||rev<INT_MIN)
    {
        return 0;
    }
    return rev;
}
// @lc code=end

