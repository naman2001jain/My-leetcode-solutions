class Solution {
public:
    
    vector<int> xmoves = {1, 0, -1, 0};
    vector<int> ymoves = {0, 1, 0, -1};
    
    bool isSafe(vector<vector<char>> &grid, vector<vector<bool>> &visited, int x, int y){
        int R = grid.size();
        int C = grid[0].size();
        return (x>=0 && x<R && y>=0 && y<C && !visited[x][y] && grid[x][y]=='1');
    }
    
    void dfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, int i, int j){
        
        visited[i][j] = true;
        int nextX, nextY;
        for(int k=0;k<4;k++){
            nextX = i+ xmoves[k];
            nextY = j+ymoves[k];
            if(isSafe(grid, visited, nextX, nextY)){
                dfs(grid, visited, nextX, nextY);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        vector<vector<bool>> visited(R,vector<bool>(C, false));
        int res = 0;
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(isSafe(grid, visited, i, j)) {
                    res++;
                    dfs(grid, visited, i, j);
                }                       
            }
        }
        return res;
    }
};