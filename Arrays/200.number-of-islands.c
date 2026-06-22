/*
 * @lc app=leetcode id=200 lang=c
 *
 * [200] Number of Islands
 */

// @lc code=start
//Arrays
//number-of-islands
//Time Complexity: O(m*n) where m is the number of rows and n is the number of columns in the grid. We visit each cell once, so the time complexity is proportional to the total number of cells in the grid.
//Space Complexity: O(m*n) in the worst case, where the entire grid is filled with land ('1'). In this case, the depth of the recursion stack can go up to m*n, leading to O(m*n) space complexity. In the average case, the space complexity is O(min(m,n)) since the maximum depth of the recursion stack is limited by the smaller dimension of the grid.
//Approach: We can use Depth First Search (DFS) to traverse the grid. We iterate through each cell in the grid, and when we encounter a land cell ('1'), we increment the island count and perform a DFS to mark all connected land cells as water ('0'). This way, we ensure that we only count each island once. The DFS function recursively explores all adjacent land cells (up, down, left, right) and marks them as water to avoid counting them again. Finally, we return the total count of islands found in the grid.
void dfs(char **grid,int i,int j,int m,int n)
{
    if(i<0||j<0||i>=m||j>=n||grid[i][j]=='0')
    {
        return;
    }
    grid[i][j]='0';
    dfs(grid,i-1,j,m,n);
    dfs(grid,i+1,j,m,n);
    dfs(grid,i,j+1,m,n);
    dfs(grid,i,j-1,m,n);
}


int numIslands(char** grid, int gridSize, int* gridColSize) {
    int m=gridSize,count=0;
    int n=gridColSize[0];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(grid[i][j]=='1')
            {
                count++;
                dfs(grid,i,j,m,n);
            }
        }
    }
    return count;
    
} 

// @lc code=end

