//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class disjointSet{
    vector<int>size,parent;
    public:
    disjointSet(int n)
    {
        size.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
    }
    int findUPar(int node)
    {
        if(parent[node]==node)
        {
            return node;
        }
        return parent[node]=findUPar(parent[node]);
    }
    void unionBySize(int u, int v)
    {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if(pu==pv){
            return;
        }
        if(size[pu]<size[pv])
        {
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else
        {
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        disjointSet ds(V);
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<V;i++)
        {
            for(auto it : adj[i])
            {
                edges.push_back({it[1],{i,it[0]}});
            }
        }
        sort(edges.begin(),edges.end());
        int netWt =0;
        for(auto it : edges)
        {
            int wt= it.first;
            int u = it.second.first;
            int v = it.second.second;
            if(ds.findUPar(u)!=ds.findUPar(v))
            {
                netWt+=wt;
                ds.unionBySize(u,v);
            }
        }
    
    return netWt;
}};

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