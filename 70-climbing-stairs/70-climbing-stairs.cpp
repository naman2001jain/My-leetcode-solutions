class Solution {
public:
    int climbStairs(int n, vector<int> &dp) {
        if(n<=2){
            return n; 
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        dp[0] = 0;
        dp[1] = 1;
        int res = 0;
        res += climbStairs(n-1, dp) + climbStairs(n-2, dp);
        return dp[n] = res;
    }
    int climbStairs(int n){
        vector<int> dp(50, -1);
        return climbStairs(n, dp);
    }
};