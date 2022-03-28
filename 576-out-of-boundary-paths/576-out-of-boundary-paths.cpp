class Solution {
public:
    vector<int> xmoves = {0,0,1,-1};
    vector<int> ymoves = {1,-1,0,0};
    int r = pow(10,9) + 7;
    int dp[55][55][55];//dp[maxMove][m][n]
    int rec(const int &m, const int &n, int maxMove, int startRow, int startColumn){
        if(maxMove<0){
            return 0;
        }
        if(startRow<0 || startRow>=m || startColumn<0 || startColumn>=n){
            return 1;
        }      
        if(dp[maxMove][startRow][startColumn]!=-1){
            return dp[maxMove][startRow][startColumn];
        }
        int res = 0;
        for(int k=0;k<4;k++){   
                res = (res%r + (rec(m, n, maxMove-1, startRow+xmoves[k], startColumn + ymoves[k]))%r)%r;
        }
        return dp[maxMove][startRow][startColumn] = res%r;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
       for(int i=0;i<55;i++){
           for(int j=0;j<55;j++){
               for(int k=0;k<55;k++){
                   dp[i][j][k] = -1;
               }
           }
       }
        return rec(m, n, maxMove, startRow, startColumn)%r;
    }
};