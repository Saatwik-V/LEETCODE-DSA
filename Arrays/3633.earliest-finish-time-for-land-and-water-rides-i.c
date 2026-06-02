/*
 * @lc app=leetcode id=3633 lang=c
 *
 * [3633] Earliest Finish Time for Land and Water Rides I
 */

// @lc code=start
//Arrays
//earliest-finish-time-for-land-and-water-rides-i
//Time Complexity: O(n*m) where n is the size of landStartTime and m is the size of waterStartTime.
//Space Complexity: O(1) since we are using only a constant amount of extra space to store the result and intermediate variables.
//Approach: We can iterate through all possible combinations of land and water rides. For each combination, we calculate the finish time for both scenarios: starting with a land ride followed by a water ride, and starting with a water ride followed by a land ride. We keep track of the minimum finish time across all combinations and return it as the result.  
#include <limits.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int earliestFinishTime(int* landStartTime, int landStartTimeSize,
                       int* landDuration, int landDurationSize,
                       int* waterStartTime, int waterStartTimeSize,
                       int* waterDuration, int waterDurationSize) {

    int result = INT_MAX;

    // Land → Water
    for (int i = 0; i < landStartTimeSize; i++) {
        for (int j = 0; j < waterStartTimeSize; j++) {
            int finishLand = landStartTime[i] + landDuration[i];
            int startWater = max(finishLand, waterStartTime[j]);
            int finish = startWater + waterDuration[j];

            if (finish < result)
                result = finish;
        }
    }

    // Water → Land
    for (int j = 0; j < waterStartTimeSize; j++) {
        for (int i = 0; i < landStartTimeSize; i++) {
            int finishWater = waterStartTime[j] + waterDuration[j];
            int startLand = max(finishWater, landStartTime[i]);
            int finish = startLand + landDuration[i];

            if (finish < result)
                result = finish;
        }
    }

    return result;
}
// @lc code=end

