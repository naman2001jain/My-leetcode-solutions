class Solution {
public:
    int count=0;
    
    vector<int> xmoves = {1, -1, 0, 0};
    vector<int> ymoves = {0, 0, 1, -1};
    int k = xmoves.size();
    bool isSafe(vector<vector<int>> &grid, vector<vector<bool>> &visited, int x, int y, const int &R, const int &C){
        return (x>=0 && x<R && y>=0 && y<C && grid[x][y]!=-1 && !visited[x][y]);
    }
    
    
    void solve(int countzero, vector<vector<int>> &grid, vector<vector<bool>> &visited, int x, int y, const int &R, const int &C){
        
        if(!isSafe(grid,visited, x, y, R, C)){
            return;
        }
        
        if(grid[x][y]==2 && countzero<0){
            count++;
            return;
        }
        
        if(isSafe(grid, visited, x, y, R, C)){
            visited[x][y] = true;
            for(int i=0;i<k;i++){
                int nextx = x+xmoves[i];
                int nexty = y+ymoves[i];
                solve(countzero-1, grid, visited, nextx, nexty, R, C);
            }
            visited[x][y] = false;
        }
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        
        vector<vector<bool>> visited(R, vector<bool>(C, false));
        int countzero = 0;
        int r,c;
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(grid[i][j]==0){
                    countzero++;
                }
                if(grid[i][j]==1){
                    r=i;
                    c=j;
                }
            }
        }
        solve(countzero , grid, visited, r, c, R, C);
        
        return count;
    }
};