/*
 * @lc app=leetcode id=682 lang=c
 *
 * [682] Baseball Game
 */

// @lc code=start
//stacks
//baseball-game
//Time Complexity: O(n) where n is the number of operations. We traverse the operations array once, and for each operation, we perform a constant amount of work (either pushing or popping from the stack). Therefore, the overall time complexity is O(n).
//Space Complexity: O(n) where n is the number of operations. In the worst case, we may need to store all the scores in the stack, leading to O(n) space complexity. However, in practice, the space used by the stack will be less than n, as some operations may remove scores from the stack.
//Approach: We can use a stack to keep track of the scores. For each operation, we perform the following actions:
//1. If the operation is a number, we convert it to an integer and push it onto the stack.
//2. If the operation is "C", we pop the top score from the stack, effectively removing it.
//3. If the operation is "D", we double the top score on the stack and push the result onto the stack.
//4. If the operation is "+", we pop the top two scores from the stack, calculate their sum, and push the result onto the stack. We then push the two original scores back onto the stack to maintain their order.
//After processing all operations, we sum up the scores in the stack to get the final result. 
int calPoints(char** operations, int operationsSize) {
    int stack[1001];
    int top=-1,t1,t2,t3;
    int result=0;
    for(int i=0;i<operationsSize;i++)
    {
        if(strcmp(operations[i],"+")==0)
        {
            t1=stack[top];
            t2=stack[top-1];
            t3=t1+t2;
            stack[++top]=t3;
        }
        else if(strcmp(operations[i],"D")==0)
        {
            t1=stack[top];
            t2=t1*2;
            stack[++top]=t2;
        }
        else if(strcmp(operations[i],"C")==0)
        {
            t3=stack[top--];
        }
        else{
            stack[++top]=atoi(operations[i]);
        }
    }
    while(top!=-1)
    {
        t1=stack[top--];
        result+=t1;
    }
    return result;
}
// @lc code=end

