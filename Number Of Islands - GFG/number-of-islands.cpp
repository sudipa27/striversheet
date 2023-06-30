//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class DisjointSet{
    public:
    vector<int> parent, sizes;
    DisjointSet(int n)
    {
        parent.resize(n+1);
        sizes.resize(n+1,1);
        for(int i=0;i<n;i++)
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
    void unionbysize(int u, int v)
    {
        int pu = parent[u];
        int pv = parent[v];
        if(pu==pv)
        {
            return;
        }
        
        if(sizes[pu]<sizes[pv])
        {
            parent[pu]=pv;
            sizes[pv]+=sizes[pu];
        }
        else
        {
            parent[pv]=pu;
            sizes[pu]+=sizes[pv];
        }
    }
    
};
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
       DisjointSet ds(n*m);
       vector<vector<int>> vis(n, vector<int>(m,0));
       int cnt=0;
       vector<int> ans;
       for(auto it : operators)
       {
           int row = it[0];
           int col = it[1];
           if(vis[row][col]==1)
           {
               ans.push_back(cnt);
               continue;
           }
           
               vis[row][col]=1;
               cnt++;
               vector<pair<int,int>> dis ={{1,0},{0,1},{-1,0},{0,-1}};
               for(auto it : dis)
               {
                   int nr = row+it.first;
                   int nc = col+it.second;
                   if(nr>=0 && nr<n && nc>=0 && nc<m)
                   {
                       if(vis[nr][nc]==1)
                       {
                           int nodeNo= row*m+col;
                           int newNode = nr*m+nc;
                           if(ds.findUPar(nodeNo)!=ds.findUPar(newNode))
                           {
                               cnt--;
                               ds.unionbysize(nodeNo,newNode);
                           }
                       }
                   }}
               
               ans.push_back(cnt);
           }
       
       return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends