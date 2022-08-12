//major twick is p[node]!=neigh

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(vector<bool> &v,vector<int> &p,vector<int> adj[],int node){
        v[node] = true;
        for(auto neigh:adj[node]){
            if(v[neigh]==false){
                p[neigh] = node;
                if(dfs(v,p,adj,neigh))return true;
            }else if(p[node]!=neigh){
                return true;
            }
        }
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> parent(V,INT_MAX);
        vector<bool> visited(V,false);
        parent[0]=-1;
        for(int i=0;i<V;i++){
            if(visited[i]==false){
                if(dfs(visited,parent,adj,i))return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
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
}
// } Driver Code Ends
