class Solution {
public:
    vector<int> xmoves = {1, 0, -1, 0};
    vector<int> ymoves = {0, 1, 0, -1};
    
    bool isSafe(vector<vector<int>> &grid, vector<vector<bool>> &visited, int x, int y){
        int R = grid.size();
        int C = grid[0].size();
        return (x>=0 && x<R && y>=0 && y<C && !visited[x][y] && grid[x][y]==1);
    }
    void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int i, int j, int &area){
        area += 1;
        visited[i][j] = true;
        int nextX, nextY;
        for(int k=0;k<4;k++){
            nextX = i+ xmoves[k];
            nextY = j+ymoves[k];
            if(isSafe(grid, visited, nextX, nextY)){
                
                dfs(grid, visited, nextX, nextY, area);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        int prevArea = 0, currArea=0;
        vector<vector<bool>> visited(R,vector<bool>(C, false));
        
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(isSafe(grid, visited, i, j)) {
                    
                    dfs(grid, visited, i, j, prevArea);
                    currArea = max(prevArea, currArea);
                    prevArea = 0;
                }                       
            }
        }
        return currArea;
    }
};