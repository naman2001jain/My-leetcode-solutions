class Solution {
public:
    
    int rec(int m, int n, vector<vector<int>> &dp){
        if(m==0 || n==0){
            return 1;
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        int left = rec(m, n-1, dp);
        int top = rec(m-1, n, dp);
        return dp[m][n] = left + top;
        
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return rec(m-1, n-1, dp);
    }
};