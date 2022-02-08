class Solution {
public:
//     int dp[205][205];
//     int rec(vector<vector<int>> &triangle, int i, int j){
//         if(i>=triangle.size() || j>=triangle[i].size()){
//             return 0;
//         }
//         if(dp[i][j]!=-1){
//             return dp[i][j];
//         }
//         return dp[i][j] = triangle[i][j] + min(rec(triangle, i+1,j), rec(triangle,i+1,j+1));
//     }
    
//     int minimumTotal(vector<vector<int>>& triangle) {
//         for(int i=0;i<205;i++){
//             for(int j=0;j<205;j++){
//                 dp[i][j] = -1;
//             }
//         }
//         int ans = rec(triangle,0,0);    
//         return ans;
//     }
    int minimumTotal(vector<vector<int>>& traingle) {
        
        int n = traingle.size ();
        if (n == 1) return traingle[0][0];
        vector <int> dp (n + 1, INT_MAX);
        dp[1] = traingle[0][0];
        int cs = 1;
        
        for (int i = 2; i <= n; i++) {
            cs++;
            int opp = INT_MAX;
            for (int j = 1; j <= cs; j++) {
                int temp = dp[j];
                dp[j] = min (opp, dp[j]) + traingle[i - 1][j - 1];
                opp = temp;
            }
        }
        
        int ans = INT_MAX;
        for (int i = 1; i <= n; i++) {
            ans = min (ans, dp[i]);
        }
        
        return ans;
    }
};