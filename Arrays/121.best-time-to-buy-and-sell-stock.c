/*
 * @lc app=leetcode id=121 lang=c
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
//Arrays
//best-time-to-buy-and-sell-stock
//Time Complexity: O(n) where n is the length of the input array. We traverse the array once.
//Space Complexity: O(1) since we are using only a constant amount of   extra space to store the result and intermediate variables.
//Approach: We can iterate through the array while keeping track of the minimum price seen so far and the maximum profit that can be achieved. We initialize minprice to the largest possible integer value (INT_MAX) to ensure that any price in the array will be less than minprice. We also initialize profit and result to 0. As we iterate through the array, we update minprice if we find a price that is lower than the current minprice. If we find a price that is higher than minprice, we calculate the profit by subtracting minprice from the current price. If this profit is greater than the current result, we update result with the new profit. Finally, we return result as the maximum profit that can be achieved from a single buy and sell transaction.
#include <limits.h>
int maxProfit(int* prices, int pricesSize) {
    int profit=0,minprice=INT_MAX,result=0;
    for(int i=0;i<pricesSize;i++)
    {
        if(prices[i]<minprice)
        {
            minprice=prices[i];
        }
        else{
            profit=prices[i]-minprice;
            if(profit>result)
            {
                result=profit;
            }

        }


    }
    return result;
}
// @lc code=end

