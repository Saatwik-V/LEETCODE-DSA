/*
 * @lc app=leetcode id=1732 lang=c
 *
 * [1732] Find the Highest Altitude
 */

// @lc code=start
//Arrays
//find-the-highest-altitude
//Time Complexity: O(n) where n is the length of the input array. We iterate through the gain array once to calculate the altitude at each point and find the maximum altitude.
//Space Complexity: O(1) since we are using only a constant amount of extra space to store the result and intermediate variables.
//Approach: We can iterate through the gain array while keeping track of the current altitude and the maximum altitude reached. We initialize res to the smallest possible integer value (INT_MIN) to ensure that any altitude calculated will be greater than res. We also initialize alt to 0, which represents the starting altitude. As we iterate through the gain array, we add each gain value to alt to calculate the current altitude. If the current altitude is greater than res, we update res with the new maximum altitude. After iterating through the entire gain array, if res is less than or equal to 0, it means that the highest altitude reached is at most 0, so we return 0. Otherwise, we return res as the highest altitude reached.
#include <limits.h> 
int largestAltitude(int* gain, int gainSize) {
    int res=INT_MIN,alt=0;
    for(int i=0;i<gainSize;i++)
    {
        alt+=gain[i];
        if(alt>res)
        {
            res=alt;
        }
    }
    if(res<=0)
    {
        return 0;
    }
    return res;
    
}
// @lc code=end

