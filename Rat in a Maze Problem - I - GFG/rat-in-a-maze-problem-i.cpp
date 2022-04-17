// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    vector<char> possibleMoves = {'U', 'D', 'L', 'R'};
    vector<int> xmoves = {-1,1,0,0};
    vector<int> ymoves = {0,0,-1,1};
    
    bool isSafe(vector<vector<bool>> &visited,vector<string> &res, vector<vector<int>> &m, int n, int x, int y){
        return (x>=0 && x<n && y>=0 && y<n && !visited[x][y] && m[x][y]!=0);
    }
    
    void findPath(vector<vector<bool>> &visited,vector<string> &res, string &pathsofar, vector<vector<int>> &m, int n, int x, int y){

        int k=possibleMoves.size();
        
        if(x==n-1 && y==n-1 && m[x][y]){
            res.push_back(pathsofar);
            return;
        }
        
        // for(int i=0;i<k;i++){
            
        //     if(isSafe(visited, res, m, n, nextx, nexty)){
        //         visited[x][y] = true;
        //         pathsofar.push_back(possibleMoves[i]);
        //         findPath(visited, res, pathsofar, m, n, nextx, nexty);
        //         pathsofar.pop_back();
        //         visited[x][y] = false;
        //     }
        // }
        
        if(isSafe(visited, res, m, n, x, y)){
            visited[x][y] = true;
            for(int i=0;i<k;i++){
                int nextx = x+xmoves[i];
                int nexty = y+ymoves[i];
                pathsofar.push_back(possibleMoves[i]);
                findPath(visited, res, pathsofar, m, n, nextx, nexty);
                pathsofar.pop_back();
            }
            visited[x][y] = false;
        }
        
        
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> res;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        string pathsofar="";
        findPath(visited,res, pathsofar, m, n, 0,0);
        return res;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends