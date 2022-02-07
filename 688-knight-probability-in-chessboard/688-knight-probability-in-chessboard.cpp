class Solution {
public:
    
    double dp[27][27][105];
    
    double rec(const int &n,int move,int i,int j){
        
        // BASE CONDITION
        
        if(i<0 || j<0 || i>=n || j>=n){
            return 0.0;
        }
        if(move == 0){
            return 1.0;
        }
        if(dp[i][j][move]!=-1.0){
            return dp[i][j][move];
        }
        
        double ans = 0.0;
        int dx[] = {-1,-1,1,1,-2,-2,2,2};
        int dy[] = {-2,2,2,-2,-1,1,-1,1};
        
         for(int k=0;k<8;k++){
             int x = i + dx[k];
             int y = j + dy[k];
             
             ans = ans + rec(n,move-1,x,y)/8.0;
         }
        
        return dp[i][j][move] = ans;
        
        
    }
    
    double knightProbability(int n, int k, int row, int column) {
        for(int i=0;i<27;i++){
            for(int j=0;j<27;j++){
                for(int x=0;x<105;x++){
                    dp[i][j][x] = -1.0;
                }
            }
        }
        double prob = rec(n,k,row,column);
        
        return prob;
    }
};