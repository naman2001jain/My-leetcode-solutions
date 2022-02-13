// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool detect(int s, vector<bool> &visited, vector<bool> &current, vector<int> adj[]){
        visited[s] = true;
        current[s] = true;
        vector<int>:: iterator itr;
        for(itr = adj[s].begin(); itr != adj[s].end();itr++){
            if(visited[*itr]==false){
                if(detect(*itr, visited, current, adj)){
                    return true;
                }
            }
            if(current[*itr]){
                return true;
            }
        }
        current[s] = false;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        vector<bool> current(V, false);
        for(int i=0;i<V;i++){
            if(visited[i]==false){
                if(detect(i, visited, current, adj)){
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