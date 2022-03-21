// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    vector<int> xmoves = {0,0,1,-1};
    vector<int> ymoves = {1,-1,0,0};
    bool isSafe(vector<vector<int>> &grid, vector<vector<bool>> &visited, int x, int y){
        int R = grid.size();
        int C = grid[0].size();
        return (x>=0 && x<R && y>=0 && y<C && !visited[x][y] && grid[x][y]!=0);
    }
    
    bool dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int x, int y, const int &R, const int &C){
        visited[x][y] = true;
        if(grid[x][y]==2){
            return true;
        }
        for(int k=0;k<4;k++){
            int nextx = x+xmoves[k];
            int nexty = y+ymoves[k];
            if(isSafe(grid, visited, nextx, nexty) && dfs(grid, visited, nextx, nexty, R, C)){
                return true;
            }
        }
        return false;
    }
    
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int R = grid.size();
        int C = grid[0].size();
        vector<vector<bool>> visited(R, vector<bool>(C, false));
        
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(grid[i][j]==1){
                    return dfs(grid, visited, i, j, R, C);
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends