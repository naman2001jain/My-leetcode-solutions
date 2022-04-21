// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    
    void bfs(vector<int> adj[], vector<int>&res ,vector<bool> &visited, queue<int> &q){
        if(q.empty()){
            return;
        }
        auto temp = q.front();
        q.pop();
        if(!visited[temp]){
            visited[temp] = true;
            res.push_back(temp);
        }
        
        for(auto x: adj[temp]){
            if(!visited[x]){
                q.push(x);
            }
        }
        
        bfs(adj, res, visited, q);
    }
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> res;
        vector<bool> visited(V, false);
        queue<int> q;
        q.push(0);
        
        bfs(adj,res, visited, q);
        
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends