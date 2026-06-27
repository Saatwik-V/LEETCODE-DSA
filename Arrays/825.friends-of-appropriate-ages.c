/*
 * @lc app=leetcode id=825 lang=c
 *
 * [825] Friends Of Appropriate Ages
 */

// @lc code=start
//Arrays
//freinds of appropriate age
//time complexity:(O(120^2));//instead of worst case n being 20,000*20,000
//space complexity:O(120)//frequency array
//approach: Use a frequency array for all 120 ages and then use the condition in that array.
int numFriendRequests(int* ages, int agesSize) {
    int* freq=(int*)malloc(121*sizeof(int));
    int count=0;
    for(int i=1;i<=120;i++)
    {
        freq[i]=0;
    }
    for(int i=0;i<agesSize;i++)
    {
        freq[ages[i]]++;
    }
    for(int i=1;i<=120;i++)
    {
        if(freq[i]==0)continue;
        for(int j=1;j<=120;j++)
        {
            if(freq[j]==0)continue;
            if(j>(0.5*i+7)&&j<=i)
            {
                if(i==j)
                {
                    count=count+(freq[i]*(freq[i]-1));
                }
                else{
                    count+=freq[i]*freq[j];
                }
            }
        }
    }
    return count;
}
// @lc code=end

