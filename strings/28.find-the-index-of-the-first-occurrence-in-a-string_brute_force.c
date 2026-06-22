/*
 * @lc app=leetcode id=28 lang=c
 *
 * [28] Find the Index of the First Occurrence in a String
 */

// @lc code=start
//Strings
//find-the-index-of-the-first-occurrence-in-a-string
//Time Complexity: O(n*m) where n is the length of haystack and m is the length of needle. In the worst case, we may have to compare each character of haystack with each character of needle, leading to O(n*m) time complexity.
//Space Complexity: O(1) since we are using only a constant amount of extra space to store the variables used in the function. We are not using any additional data structures that grow with the input size.
//Approach: We can iterate through each character of haystack and compare it with the corresponding character of needle. If we find a mismatch, we can break out of the inner loop and continue checking from the next character in haystack. If we successfully match all characters of needle, we can return the starting index of the match in haystack. If we reach the end of haystack without finding a match, we can return -1 to indicate that needle is not present in haystack.
int strStr(char* haystack, char* needle) {
    int m=strlen(needle),j;
    int n=strlen(haystack);
    for(int i=0;i<=n-m;i++)    
    {
        j=0;
        while(j<m&&(needle[j]==haystack[i+j]))
        {
            j++;
        }
        if(j==m)
        {
            return i;
        }
        
    }
    return -1;
}
// @lc code=end

