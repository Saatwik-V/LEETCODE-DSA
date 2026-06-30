/*
 * @lc app=leetcode id=1475 lang=c
 *
 * [1475] Final Prices With a Special Discount in a Shop
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//Arrays
//final-prices-with-a-special-discount-in-a-shop
//Time Complexity: O(n^2) where n is the size of prices. We have
// two nested loops to iterate through all possible pairs of prices, leading to O(n^2) time complexity.
//Space Complexity: O(1) since we are modifying the input array in place and not using any additional data structures that grow with the input size. We are only using a constant amount of extra space for the variables used in the function.
//Approach: We can use two nested loops to iterate through all possible pairs of prices. For each price at index i, we check the subsequent prices at index j (where j > i) to find the first price that is less than or equal to the price at index i. If we find such a price, we apply the discount by subtracting the price at index j from the price at index i. If we do not find any such price, we leave the price at index i unchanged. Finally, we return the modified prices array.
int* finalPrices(int* prices, int pricesSize, int* returnSize) {
    *returnSize=pricesSize;
    for(int i=0;i<pricesSize-1;i++)
    {
        for(int j=i+1;j<pricesSize;j++)
        {
            if(prices[j]<=prices[i])
            {
                prices[i]=prices[i]-prices[j];
                break;
            }
        }
    }
    return prices;

    
}
// @lc code=end

