/*
 * @lc app=leetcode id=3635 lang=c
 *
 * [3635] Earliest Finish Time for Land and Water Rides II
 */

// @lc code=start
//Arrays
//earliest-finish-time-for-land-and-water-rides-ii
//Time Complexity: O(n*m) where n is the size of landStartTime and m is the size of waterStartTime.
//Space Complexity: O(1) since we are using only a constant amount of extra space to store the result and intermediate variables.
//Approach: We can iterate through all possible combinations of land and water rides. For each combination, we calculate the finish time for both scenarios: starting with a land ride followed by a water ride, and starting with a water ride followed by a land ride. We keep track of the minimum finish time across all combinations and return it as the result.
#include <limits.h>
int solve(int *start1,int start1Size,int *duration1,int duration1Size,int *start2,int start2Size,int *duration2,int duration2Size)
{
    int finish1=INT_MAX;
    for(int i=0;i<start1Size;i++)
    {
        finish1=fmin(finish1,start1[i]+duration1[i]);
    }
    int finish2 = INT_MAX;
    for (int j = 0; j < start2Size; j++) {
        finish2 = fmin(finish2, fmax(finish1, start2[j]) + duration2[j]);
    }

    return finish2;
}



int earliestFinishTime(int* landStartTime, int landStartTimeSize, int* landDuration, int landDurationSize, int* waterStartTime, int waterStartTimeSize, int* waterDuration, int waterDurationSize) {

    int landToWater = solve(landStartTime, landStartTimeSize,           landDuration, landDurationSize, waterStartTime, waterStartTimeSize, waterDuration, waterDurationSize);
    
    int waterToLand = solve(waterStartTime, waterStartTimeSize, waterDuration, waterDurationSize, landStartTime, landStartTimeSize, landDuration, landDurationSize);

    return fmin(landToWater, waterToLand);
    
}
// @lc code=end

