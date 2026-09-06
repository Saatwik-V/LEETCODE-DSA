/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// @lc code=start

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int>temp;
        int n=nums.size();
        k=k%n;
        for(int i=n-k;i<n;i++)
        {
            temp.push_back(nums[i]);
        }
        for(int i=n-k-1;i>=0;i--)
        {
            nums[i+k]=nums[i];
        }
        for(int i=0;i<k;i++)
        {
            nums[i]=temp[i];
        }
     
    }
};
// @lc code=end

