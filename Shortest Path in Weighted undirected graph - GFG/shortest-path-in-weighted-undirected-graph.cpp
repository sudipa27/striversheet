//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
      vector<pair<int,int>> adj[n+1];
      for(int i=0;i<edges.size();i++)
      {
          int u = edges[i][0];
          int v = edges[i][1];
          int w = edges[i][2];
          adj[u].push_back({v,w});
          adj[v].push_back({u,w});
      }
      priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;;
      vector<int> dist(n+1);
      for(int i=0;i<=n;i++)
      {
          dist[i]=1e9;
      }
      dist[1]=0;
      vector<int> parent(n+1);
      for(int i=0;i<=n;i++)
      {
          parent[i]=i;
      }
      pq.push({0,1});
      while(!pq.empty())
      {
          auto it = pq.top();
          int node= it.second;
          int dis = it.first;
          pq.pop();
          for(auto it : adj[node])
          {
              int edg= it.first;
              int wt= it.second;
              if(wt+dis < dist[edg])
              {
                  dist[edg]=wt+dis;
                  pq.push({dist[edg],edg});
                  parent[edg]=node;
              }
          }
      }
      if(dist[n]==1e9)
      {
        return{-1};
      }
      vector<int> ans;
      int node = n;
      while(parent[node]!=node)
      {
          ans.push_back(node);
          node= parent[node];
      }
      ans.push_back(1);
      reverse(ans.begin(),ans.end());
      return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends