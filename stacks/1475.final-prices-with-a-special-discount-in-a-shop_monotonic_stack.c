/*
 * @lc app=leetcode id=1475 lang=c
 *
 * [1475] Final Prices With a Special Discount in a Shop
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//stacks
//final-prices-with-a-special-discount-in-a-shop
//Time Complexity: O(n) where n is the size of prices. We traverse the prices array once, and for each price, we may pop elements from the stack at most once, leading to O(n) time complexity.
//Space Complexity: O(n) in the worst case, where all prices are in increasing order. In this case, we may push all prices onto the stack, leading to O(n) space complexity. In the average case, the space complexity is O(k), where k is the maximum number of prices that can be on the stack at any given time. This is because we only keep track of the prices that are greater than the current price, and once we find a price that is less than or equal to the current price, we pop elements from the stack until we find a price that is less than or equal to the current price or the stack becomes empty.
//Approach: We can use a stack to keep track of the prices that are greater than the current price. We traverse the prices array from right to left. For each price, we pop elements from the stack until we find a price that is less than or equal to the current price or the stack becomes empty. If the stack is not empty, we apply the discount by subtracting the price at the top of the stack from the current price. If the stack is empty, we leave the current price unchanged. We then push the current price onto the stack. Finally, we return the modified prices array.
int* finalPrices(int* prices, int pricesSize, int* returnSize) {
    int *ans=(int *)malloc(pricesSize*sizeof(int));
    int stack[500];
    int top=-1;
    *returnSize=pricesSize;
    for(int i=pricesSize-1;i>=0;i--)
    {
        while(top!=-1&&stack[top]>prices[i])
        {
            int a=stack[top--];
        }
        if(top==-1){
            ans[i]=prices[i];
        }
        else{
            ans[i]=prices[i]-stack[top];
        }
        stack[++top]=prices[i];
    }
    return ans;
    
}
// @lc code=end

