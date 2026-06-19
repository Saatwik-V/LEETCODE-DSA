/*
 * @lc app=leetcode id=14 lang=c
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
//strings
//longest-common-prefix
//Time Complexity: O(n * m) where n is the number of strings in the input array and m is the length of the longest common prefix. In the worst case, we may have to compare each character of the longest common prefix with all n strings, leading to O(n * m) time complexity.
//Space Complexity: O(1) since we are modifying the input string in place and not using any additional data structures that grow with the input size. We are only using a constant amount of extra space for the variables used in the function.
 //Approach: We can iterate through each character of the first string in the input array and compare it with the corresponding character in all other strings. If we find a mismatch or reach the end of any string, we can terminate the loop
char* longestCommonPrefix(char** strs, int strsSize) {
    for(int i=0;strs[0][i]!='\0';i++)
    {
        char ch=strs[0][i];
        for(int j=1;j<strsSize;j++)
        {
            if(strs[j][i]!=ch||strs[j][i]=='\0')
            {
                strs[0][i]='\0';
                    return strs[0];
            }
        }

    }

    return strs[0];
}
// @lc code=end

