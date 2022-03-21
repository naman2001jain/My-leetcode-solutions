// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to count paths between two vertices in a directed graph.
    
    void dfs(vector<int> adj[], vector<bool> &visited, int source, int destination, int &res){
        visited[source] = true;
        if(source == destination){
            res++;
            return;
        }
        for(auto x: adj[source]){
            if(!visited[x]){
                dfs(adj, visited, x, destination, res);
                visited[x] = false;
            }
        }
    }
    
    int countPaths(int V, vector<int> adj[], int source, int destination) {
        vector<bool> visited(V, false);
        int res = 0;
        dfs(adj, visited, source, destination, res);
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // adj[v].push_back(u);
        }
        int source, destination;
        cin >> source >> destination;
        Solution obj;
        cout << obj.countPaths(V, adj, source, destination) << endl;
    }
    return 0;
}  // } Driver Code Ends