class Solution {
public:
    int dp[1005][1005];
    int lcs(string &text1, string &text2, int m, int n){
        if(m==0 || n==0){
            return 0;
        }
        
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        if(text1[m-1] == text2[n-1]){
            return dp[m][n] = 1+lcs(text1, text2, m-1,n-1);
        }else{
            return dp[m][n] = max(lcs(text1, text2, m-1, n), lcs(text1, text2, m, n-1));
        }
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                dp[i][j] = -1;
            }
        }
        return lcs(text1, text2, m, n);
    }
};