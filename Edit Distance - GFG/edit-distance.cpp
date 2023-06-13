//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int func(int ind1, int ind2, string s, string t, vector<vector<int>>&dp)
  {
      if(ind1<0){ return ind2+1;}
      if(ind2<0){ return ind1+1;}
      if(dp[ind1][ind2] != -1)
      {
          return dp[ind1][ind2];
      }
      if(s[ind1]==t[ind2])
      {
          return dp[ind1][ind2] = 0+ func(ind1-1, ind2-1,s,t,dp);
      }
      else
      {
          int insert = 1+ func(ind1,ind2-1,s,t,dp);
          int replace= 1+ func(ind1-1,ind2-1,s,t,dp);
          int deletee = 1+func(ind1-1, ind2, s,t,dp);
         return  dp[ind1][ind2] = min(insert, min(deletee,replace));
      }
  }
    int editDistance(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<vector<int>> dp(n+1, vector<int>(m,-1));
        return func(n-1,m-1,s,t,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends