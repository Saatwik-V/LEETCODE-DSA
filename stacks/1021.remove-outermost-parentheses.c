/*
 * @lc app=leetcode id=1021 lang=c
 *
 * [1021] Remove Outermost Parentheses
 */

// @lc code=start
//stacks
//remove-outermost-parentheses
//Time Complexity: O(n) where n is the length of the input string. We traverse the string once, and for each character, we perform constant time operations to update the depth and build the result string. Therefore, the overall time complexity is linear with respect to the length of the input string.
//Space Complexity: O(n) where n is the length of the input string. We create a new string to store the result, which can be at most the same length as the input string. In the worst case, if all parentheses are outermost, the result string will have the same length as the input string. Therefore, the space complexity is linear with respect to the length of the input string.
//Approach: We can use a depth counter to keep track of the current depth of the parentheses. We iterate through each character of the input string. When we encounter an opening parenthesis '(', we check if the current depth is greater than 0. If it is, we add the opening parenthesis to the result string. We then increment the depth counter. When we encounter a closing parenthesis ')', we decrement the depth counter first. If the current depth is still greater than 0 after decrementing, we add the closing parenthesis to the result string. This way, we effectively remove the outermost parentheses while preserving the inner structure of the parentheses. Finally, we return the result string containing the modified parentheses.

char* removeOuterParentheses(char* s) {
    char* res=(char*)malloc((strlen(s))*sizeof(char));
    int depth=0; // like the top of the stack
    int j=0;
    for(int i=0;s[i]!='\0';i++)
    {
        
        if(s[i]=='(')
        {
            if(depth>0)
            {
                res[j++]=s[i];

            }
            depth++;
            
        }
        else{
            depth--;
            if(depth>0)
            {
                res[j++]=s[i];
            }
            
        }
        
    
    }
    res[j]='\0';
    return res;
    
}
// @lc code=end

