class Solution {
public:
    int dp[205][205];
    int rec(vector<vector<int>> &triangle, int i, int j){
        if(i>=triangle.size() || j>=triangle[i].size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        return dp[i][j] = triangle[i][j] + min(rec(triangle, i+1,j), rec(triangle,i+1,j+1));
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i=0;i<205;i++){
            for(int j=0;j<205;j++){
                dp[i][j] = -1;
            }
        }
        int ans = rec(triangle,0,0);    
        return ans;
    }
};