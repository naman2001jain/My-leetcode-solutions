class Solution {
public:
    
    
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> q;
        int level=0;
        int m = grid.size();
        int n=grid[0].size();
        int fresh = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({{i,j},level});
                }else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        int ans=0, count=0;
        while(!q.empty()){
            auto f = q.front();
            int i=f.first.first;
            int j=f.first.second;
            int level = f.second;
            q.pop();
            
            int dx[] = {-1,0,0,1};
            int dy[] = {0,-1,1,0};
            ans = max(ans,level);
            for(int k=0;k<4;k++){
                int x = i+dx[k];
                int y = j+dy[k];
                if(x>=0 && x<m && y>=0 && y<n && grid[x][y]==1 ){
                    count++;
                    grid[x][y] = 2;
                    q.push({{x,y},level+1});
                }
            }
        }
        return fresh==count?ans:-1;
    }
};