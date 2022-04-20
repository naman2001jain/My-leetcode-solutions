class Solution {
public:
    
    bool isSafe(char num, vector<vector<char>> &board, int x, int y, const int &R, const int &C){
        //horizontal check
        for(int j=0;j<R;j++){
            if(board[x][j]==num){
                return false;
            }
        }
        
        //vertical check
        for(int i=0;i<R;i++){
            if(board[i][y]==num){
                return false;
            }
        }
        
        //box check
        int X = x-x%3;
        int Y = y-y%3;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i+X][j+Y]==num){
                    return false;
                }
            }
        }
        return true;
        
    }
    
    bool solve(vector<vector<char>> &board, const int &R, const int &C){
        
        
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(board[i][j]=='.'){
                    for(char num='1';num<='9';num++){
                        if(isSafe(num, board,i,j, R, C)){
                            board[i][j] = num;
                            if(solve(board, R, C)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
                
            }
        }
        
        
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,9,9);
    }
};