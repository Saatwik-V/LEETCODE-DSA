/*
 * @lc app=leetcode id=2144 lang=c
 *
 * [2144] Minimum Cost of Buying Candies With Discount
 */

// @lc code=start
//Arrays
//minimum-cost-of-buying-candies-with-discount
//Time Complexity: O(n log n) due to sorting the array.
//Space Complexity: O(1) if we ignore the space used by the sorting algorithm, otherwise O(n) due to the space used by the sorting algorithm.
//Approach: We can sort the cost array in descending order. Then, we can iterate through the sorted array and add the cost of every candy to the result, but we skip every third candy (i.e., when the index is 2, 5, 8, etc.) since those candies are free due to the discount. Finally, we return the total cost.
int cmp(const void *a,const void *b)
 {
    return(*(int*)b-*(int*)a);
 }

int minimumCost(int* cost, int costSize) {
    qsort(cost,costSize,sizeof(int),cmp);
    int res=0;
    for(int i=0;i<costSize;i++)
    {
        if((i%3)!=2)
        {
            res+=cost[i];
        }
    }
   return res;
}
// @lc code=end

