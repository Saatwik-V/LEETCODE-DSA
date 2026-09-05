

// @lc app=leetcode id=1796 lang=c++
// @lc title=second-largest-digit-in-a-string
// @lc difficulty=Easy
// @lc topic=String,Sorting
// @lc end
//strings
//second-largest-digit-in-a-string
//Time Complexity: O(n) where n is the size of the string s. We traverse the string once, and for each character, we perform constant time operations, leading to O(n) time complexity.
//Space Complexity: O(1) as we are using a constant amount of extra space to store the largest and second largest digits, regardless of the size of the input string.
//Approach: We can traverse the string and keep track of the largest and second largest digits we encounter. We initialize two variables, largest and second, to INT_MIN. For each character in the string, we check if it is a digit (between '0' and '9'). If it is, we convert it to an integer and compare it with the largest and second largest digits. If the digit is greater than the largest digit, we update second to be the value of largest, and then update largest to be the value of the current digit. If the digit is greater than second but less than largest, we update second to be the value of the current digit. After traversing the string, if second is still INT_MIN, it means there was no second largest digit, and we return -1.
#include <bits/stdc++.h>


class Solution {
public:
    int secondHighest(string s) {
        int largest=INT_MIN;
        int second=INT_MIN;
        for(int i=0;i<s.size();i++)
        {
            int digit=s[i]-'0';
            if(digit<=9)
            {
                if(digit>largest)
                {
                    second=largest;
                    largest=digit;
                }
                else if(digit>second&&digit<largest)
                {
                    second=digit;
                }
            }             
        }
        if(second==INT_MIN)return -1;
        return second;
        
    }
};