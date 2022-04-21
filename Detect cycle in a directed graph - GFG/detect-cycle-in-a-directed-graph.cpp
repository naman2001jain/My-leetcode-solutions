// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool detect(vector<bool> &visited, vector<bool> &parent, vector<int> adj[], int node){
        visited[node] = true;
        parent[node] = true;
        for(auto x: adj[node]){
            if(!visited[x]){
                if(detect(visited, parent, adj, x)){
                    return true;
                }
            }else if(parent[x]){
                return true;
            }
        }
        parent[node] = false;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> visited(V, false);
        vector<bool> parent(V, false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(detect(visited, parent, adj, i)){
                    return true;
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends