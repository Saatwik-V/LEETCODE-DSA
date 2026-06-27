/*
 * @lc app=leetcode id=1147 lang=c
 *
 * [1147] Longest Chunked Palindrome Decomposition
 */

// @lc code=start
//Strings
//longest-chunked-palindrome-decomposition
//Time Complexity: O(n^2) where n is the length of the input string. We are using two pointers to traverse the string and comparing substrings, which takes O(n) time for each comparison. In the worst case, we may have to compare all possible substrings, leading to O(n^2) time complexity.
//Space Complexity: O(n) where n is the length of the input string. We are using two character arrays to store the left and right substrings, which requires additional space proportional to the length of the input string. In the worst case, the left and right substrings can be of length n/2 each, leading to O(n) space complexity
//Approach: We can use two pointers to traverse the input string from both ends. We maintain two character arrays to store the left and right substrings. We compare the left and right substrings at each step. If they are equal, we increment the count of chunks and reset the left and right substrings. If they are not equal, we continue to expand the left and right substrings by moving the pointers inward. We repeat this process until the two pointers meet or cross each other. Finally, if there are any remaining characters in the left substring, we increment the count of chunks by one. The final count of chunks is the result.
#include <string.h>

int longestDecomposition(char* text) {
    int n = strlen(text);
    int i = 0, j = n - 1;
    int leftStart = 0, rightEnd = n - 1;
    int ans = 0;

    char left[1001], right[1001];

    while (i <= j) {
        left[i - leftStart] = text[i];
        left[i - leftStart + 1] = '\0';

        memmove(right + 1, right, rightEnd - j);
        right[0] = text[j];
        right[rightEnd - j + 1] = '\0';

        if (strcmp(left, right) == 0) {
            if (i == j)
                ans += 1;
            else
                ans += 2;

            leftStart = i + 1;
            rightEnd = j - 1;
            left[0] = '\0';
            right[0] = '\0';
        }

        i++;
        j--;
    }

    if (left[0] != '\0')
        ans++;

    return ans;
}
// @lc code=end

