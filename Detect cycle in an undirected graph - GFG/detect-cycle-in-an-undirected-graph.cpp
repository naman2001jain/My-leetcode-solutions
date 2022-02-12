// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool detect(int s, vector<bool> &visited, int parent, vector<int> adj[]){
        visited[s] = true;
        for(int u: adj[s]){
            if(visited[u]==false){
                if(detect(u, visited, s, adj)){
                    return true;
                }
            }
            else if(parent != u){
                return true;
            }
        }
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        for(int i=0;i<V;i++){
            if(visited[i]==false){
                if(detect(i, visited, -1, adj)){
                    return true;
                }
            }
        }
        return false;
        
        
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
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends