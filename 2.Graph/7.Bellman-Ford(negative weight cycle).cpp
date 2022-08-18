//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    vector<int> d(n,INT_MAX);
	    d[0]=0;
	    for(int i=1;i<n;i++){
	        for(auto it : edges){
	            int u = it[0];
	            int v = it[1];
	            int wt = it[2];
	            if(d[u]!=INT_MAX and d[u]+wt < d[v]){
	                d[v] = d[u] + wt;
	            }
	        }
	    }
	    for(auto it : edges){
	            int u = it[0];
	            int v = it[1];
	            int wt = it[2];
	            if(d[u]+wt < d[v]){
	                return 1;
	            }
	   }
	   return 0;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
