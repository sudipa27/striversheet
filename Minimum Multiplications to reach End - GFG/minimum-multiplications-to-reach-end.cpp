//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int mod= 1e5;
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        vector<int> dist(100000, 1e9);
        queue<pair<int,int>> q;
        q.push({start,0});
        dist[start]=0;
        while(!q.empty())
        {
            int node= q.front().first;
            int steps=q.front().second;
            q.pop();
            for(auto it : arr)
            {
                int nums = (it*node)%mod;
                if(steps+1<dist[nums])
                {
                    dist[nums]=steps+1;
                
                if(end==nums)
                {
                    return steps+1;
                }
                q.push({nums,steps+1});
            }}
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends