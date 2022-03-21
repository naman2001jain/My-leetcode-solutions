// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the number of 'X' total shapes.
    vector<int> xmoves = {0,0,1,-1};
    vector<int> ymoves = {1,-1,0,0};
    
    bool isSafe(vector<vector<char>> &grid, vector<vector<bool>> &visited, int x, int y, const int &R, const int &C){
        return (x>=0 && x<R && y>=0 && y<C && !visited[x][y] && grid[x][y]=='X');
    }
    
    int dfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, int x, int y, const int &R, const int &C){
        visited[x][y] = true;
        
        int res = 0;
        for(int k=0;k<4;k++){
            int nextx = x+xmoves[k];
            int nexty = y+ymoves[k];
            if(isSafe(grid, visited, nextx, nexty, R, C)){
                res += dfs(grid, visited, nextx, nexty, R, C);
            }
        }
        return res;
    }

    int xShape(vector<vector<char>>& grid) 
    {
        int R = grid.size();
        int C = grid[0].size();
        int res = 0;
        vector<vector<bool>> visited(R, vector<bool>(C, false));
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(isSafe(grid, visited, i, j, R, C)){
                    res += 1+dfs(grid, visited, i, j, R, C);
                }
            }
        }
        return res;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends