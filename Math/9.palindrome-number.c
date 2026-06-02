/*
 * @lc app=leetcode id=9 lang=c
 *
 * [9] Palindrome Number
 */

// @lc code=start
//Math
//palindrome-number
//Time Complexity: O(log10(n)) where n is the input integer. This is because we are processing each digit of the integer once.
//Space Complexity: O(1) since we are using only a constant amount of extra space to store the result and intermediate variables.
//Approach: We can use a while loop to reverse the digits of the integer. We extract the last digit of the integer using the modulus operator and add it to the reversed number after multiplying the reversed number by 10. We then remove the last digit from the original integer by dividing it by 10. Finally, we compare the reversed number with the original integer. If they are equal, then the integer is a palindrome; otherwise, it is not. We also need to handle the case where the input integer is negative, as negative numbers cannot be palindromes. In this case, we can immediately return false. Additionally, we should consider the case where the last digit of the number is 0. In this case, the number cannot be a palindrome unless the number itself is 0. Therefore, if the last digit is 0 and the number is not 0, we can also return false.
#include <stdbool.h>
bool isPalindrome(int x) {
    int temp=x;
    unsigned int new=0;
    while(x>0)
    {
        int p=x%10;
        new=new*10+p;
        x=x/10;
    }
    return new==temp;
}
// @lc code=end

