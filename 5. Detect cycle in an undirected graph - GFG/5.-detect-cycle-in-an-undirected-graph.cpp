// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool detect(int node, vector<bool> &visited,const int &V, vector<int> adj[]){
        
        stack<int> s;
        s.push(node);
        
        while(!s.empty()){
            auto temp = s.top();
            s.pop();
            
            if(visited[temp]==false){
                visited[temp] = true;
                
                
            }else{
                return true;
            }
            for(auto x: adj[temp]){
                if(visited[x]==false){
                    s.push(x);
                }
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        bool res = false;
        vector<bool> visited(V, false);
        for(int i=0;i<V;i++){
            if(visited[i]==false)
                res = res || detect(i, visited, V, adj);
        }
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