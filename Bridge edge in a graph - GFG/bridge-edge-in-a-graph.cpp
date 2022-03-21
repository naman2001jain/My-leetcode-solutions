// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    void dfs(vector<bool> &visited, vector<int> adj[], const int &V, int source){
        visited[source] = true;
        for(auto x: adj[source]){
            if(!visited[x]){
                dfs(visited, adj, V, x);
            }
        }
    }
    void delEdge(vector<int> adj[], int u, int v)
{
    for (int i = 0; i < adj[u].size(); i++) {
        if (adj[u][i] == v) {
            adj[u].erase(adj[u].begin() + i);
            break;
        }
    }
 
    for (int i = 0; i < adj[v].size(); i++) {
        if (adj[v][i] == u) {
            adj[v].erase(adj[v].begin() + i);
            break;
        }
    }
}
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        vector<bool> visited(V, false);
        int componentsBRE = 0, componentsARE = 0;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                componentsBRE++;
                dfs(visited, adj, V, i);
            }
        }
        // cout<<componentsBRE<<endl;
        //removing the edge c--d
        delEdge(adj, c, d);
        for(int i=0;i<V;i++){
            visited[i] = false;
        }
        int res = 0;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                componentsARE++;
                dfs(visited, adj, V, i);
            }
        }
        // cout<<componentsARE<<endl;
        return componentsBRE != componentsARE;
        
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends