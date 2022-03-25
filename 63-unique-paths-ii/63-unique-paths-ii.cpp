class Solution {
public:
    
    int rec(vector<vector<int>> &grid, int m, int n, vector<vector<int>> &dp){
        
        if(m<0 || n<0){
            return 0;
        }
        if(grid[m][n]==1){
            return 0;
        }
        if(m==0 && n==0){
            return 1;
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        
        return dp[m][n] = rec(grid, m-1, n,dp) + rec(grid, m, n-1,dp);
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return rec(grid, m-1, n-1, dp);
    }
};