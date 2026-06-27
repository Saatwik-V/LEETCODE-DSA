/*
 * @lc app=leetcode id=825 lang=c
 *
 * [825] Friends Of Appropriate Ages
 */

// @lc code=start
//Arrays
//friends-of-appropriate-ages
//Time Complexity: O(n^2) where n is the size of ages. We have two nested loops to iterate through all possible pairs of ages, leading to O(n^2) time complexity.   
//Space Complexity: O(1) since we are using only a constant amount of extra space to store the count of friend requests. We are not using any additional data structures that grow with the input size. 
//Approach: We can use two nested loops to iterate through all possible pairs of ages in the input array. For each pair (ages[i], ages[j]), we check if the conditions for sending a friend request are satisfied: ages[j] must be greater than 0.5 * ages[i] + 7 and less than or equal to ages[i]. If both conditions are satisfied, we increment the count of friend requests. We repeat this process for all pairs of ages and return the total count of friend requests found in the array.    
int numFriendRequests(int* ages, int agesSize) {
    int count=0;
    for(int i=agesSize-1;i>0;i--)//x
    {
        for(int j=i-1;j>=0;j--)//y
        {
            if(ages[j]>(0.5*ages[i]+7)&&ages[j]<=ages[i])
            {
                count++;
            }
        }
    }
    for(int i=0;i<agesSize-1;i++)
    {
       for(int j=i+1;j<agesSize;j++)
        {
            if(ages[j]>(0.5*ages[i]+7)&&ages[j]<=ages[i])
            {
                count++;
            }
        }
    }
    return count;
}
// @lc code=end

