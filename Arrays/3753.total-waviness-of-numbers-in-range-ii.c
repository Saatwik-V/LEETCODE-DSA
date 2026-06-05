/*
 * @lc app=leetcode id=3753 lang=c
 *
 * [3753] Total Waviness of Numbers in Range II
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//Arrays
//total-waviness-of-numbers-in-range-ii
//Time Complexity: O(log n) where n is the size of the input range. This is because we are using a digit dynamic programming approach, which typically has a time complexity of O(d * 2 * 10 * 10 * 2) where d is the number of digits in the largest number in the range. Since d is approximately log10(n), the overall time complexity can be considered O(log n).
//Space Complexity: O(d * 2 * 10 * 10 * 2) where d is the number of digits in the largest number in the range. This is because we are using a 5-dimensional array to store the results of our dynamic programming states, where the dimensions correspond to the position of the digit, whether we are tight to the upper bound, the last digit, the second last digit, and whether we have started forming a number.
//Approach: We can use a digit dynamic programming approach to count the total waviness of numbers in the given range. We define a recursive function solve_dp that takes the current position of the digit we are processing, a tight flag to indicate whether we are still bound by the upper limit of the number, the last digit and second last digit we have processed, and a started flag to indicate whether we have started forming a number (to handle leading zeros). The function will return a Node structure that contains the count of numbers and the total waviness for the current state. We will iterate through  the possible digits for the current position, update the tight and started flags accordingly, and recursively call solve_dp for the next position. We will also check if the current digit forms a "wavy" pattern with the last two digits and update the waviness count accordingly. Finally, we will call this function for the upper bound of the range and subtract the result for the lower bound minus one to get the total waviness for the range [num1, num2].      
#include <string.h>

typedef struct {
    long long cnt;
    long long wav;
} Node;

Node dp[20][2][11][11][2];
int vis[20][2][11][11][2];
int digits[20];

Node solve_dp(int pos, int tight, int last, int secondLast, int started)
{
    if(pos == -1)
        return (Node){1, 0};  // one number, 0 waviness

    if(vis[pos][tight][last+1][secondLast+1][started])
        return dp[pos][tight][last+1][secondLast+1][started];

    int limit = tight ? digits[pos] : 9;
    Node res = {0, 0};

    for(int d = 0; d <= limit; d++)
    {
        int new_tight = (tight && d == limit);
        int new_started = started || (d != 0);

        Node temp;

        if(!new_started)
        {
            temp = solve_dp(pos-1, new_tight, -1, -1, 0);
        }
        else
        {
            temp = solve_dp(pos-1, new_tight, d, last, 1);

            if(secondLast != -1)
            {
                if((last > secondLast && last > d) ||
                   (last < secondLast && last < d))
                {
                    temp.wav += temp.cnt;   // 🔥 KEY FIX
                }
            }
        }

        res.cnt += temp.cnt;
        res.wav += temp.wav;
    }

    vis[pos][tight][last+1][secondLast+1][started] = 1;
    return dp[pos][tight][last+1][secondLast+1][started] = res;
}

long long solve(long long num)
{
    int len = 0;

    if(num == 0) digits[len++] = 0;

    while(num > 0)
    {
        digits[len++] = num % 10;
        num /= 10;
    }

    memset(vis, 0, sizeof(vis));

    return solve_dp(len-1, 1, -1, -1, 0).wav;
}

long long totalWaviness(long long num1, long long num2)
{
    return solve(num2) - solve(num1 - 1);
}
// @lc code=end

