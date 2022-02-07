class Solution {
public:
    
    vector<int> xMove = {1,0,0,-1};
    vector<int> yMove = {0,1,-1,0};
    int dp[55][55][55];
    int mod = 1000000007;
    int rec(int m, int n, int maxMove, int i, int j){
        if(i<0 || j<0 || i>=m || j>=n){
            return 1;
        }
        if(maxMove==0){
            return 0;
        }
        if(dp[i][j][maxMove]!=-1){
            return dp[i][j][maxMove];
        }
        int ans = 0;
        for(int k=0;k<4;k++){
            int x = i+xMove[k];
            int y = j+yMove[k];
            ans =(ans%mod + rec(m,n,maxMove-1,x,y)%mod)%mod;
        }
        return dp[i][j][maxMove] = ans;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        for(int i=0;i<55;i++){
            for(int j=0;j<55;j++){
                for(int k=0;k<55;k++){
                    dp[i][j][k] = -1;
                }
            }
        }
        int ans = rec(m,n,maxMove, startRow, startColumn)%mod;
        return ans;
    }
};