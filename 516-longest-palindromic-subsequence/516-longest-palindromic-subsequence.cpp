class Solution {
public:
    
    int dp[1005][1005];
    int lcs(string &s1, string &s2, int m, int n){
        if(m==0 || n==0){
            return 0;
        }
        if(dp[m][n]!=-1){return dp[m][n];}
        
        if(s1[m-1]==s2[n-1]){
            return dp[m][n] = 1+lcs(s1, s2, m-1, n-1);
        }
        else{
            return dp[m][n] = max(lcs(s1,s2, m-1,n), lcs(s1,s2,m,n-1));
        }
    }
    
    int longestPalindromeSubseq(string s1) {
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        
        int l = s1.length();
        for(int i=0;i<1005;i++){
            for(int j=0;j<1005;j++){
                dp[i][j] = -1;
            }
        }
        return lcs(s1, s2,l,l);
    }
};