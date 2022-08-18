/*
// comperator concept
#include <bits/stdc++.h>
using namespace std;
bool static comp(int a, int b){  //it sort in increasing order
    return a<b;
}
int main() {
	vector<int> v(3);
	v[0]=12;
	v[1]=8;
	v[2]=9;
	sort(v.begin(),v.end(),comp);
	for(auto it:v)cout<<it<<" ";
	return 0;
}*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	struct node{
	  int u,v,weight;
	  node(int a,int b,int c){
	      u=a;v=b;weight=c;
	  }
	};
	int findpar(int u,vector<int> &parent)//function to find parent of node u
	{
	    if(u==parent[u]) return u;
	    return parent[u]=findpar(parent[u],parent);//parent[u]= for path compression
	}
	int unionn(int u,int v,vector<int> &parent,vector<int> &rank)
	{
	    u=findpar(u,parent);v=findpar(v,parent);
	    if(rank[u]<rank[v]) parent[u]=v;
	    else if(rank[u]>rank[v]) parent[v]=u;
	    else
	    {
	        parent[v]=u;
	        rank[u]++;//increment only in this case
	    }
	}
	bool static comp(node a,node b)//comparator function
	{
	    return a.weight<b.weight;
	}
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<node> edges;
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            {
                edges.push_back(node(i,it[0],it[1]));//(node,adjnode,weight)
            }
        }
        sort(edges.begin(),edges.end(),comp);//sort based on wt in increasing order
        vector<int> parent(V),rank(V,0);
        int cost=0;
        for(int i=0;i<V;i++) parent[i]=i;//initially mark all nodes itself as a parent 
                                        //means all are different components initially
        for(auto it:edges)
        {
            if(findpar(it.v,parent)!=findpar(it.u,parent))
            {
                cost=cost+it.weight;
                unionn(it.u,it.v,parent,rank); 
            }
        }
        return cost;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
