//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
bool func(int ind, int target, vector<vector<int>> &dp, vector<int>&arr)
{
    if(target==0)
    {
        return true;
    }
    if(ind==0)
    {
        return(arr[ind]==target);
    }
    if(dp[ind][target]!=-1)
    {
        return dp[ind][target];
    }
    bool nottake=func(ind-1,target,dp,arr);
    bool take=false;
    if(arr[ind]<=target)
    {
        take=func(ind-1,target-arr[ind],dp,arr);
    }
    return dp[ind][target]=take||nottake;
}
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        vector<vector<bool>> dp(n, vector<bool>(sum+1,false));
    for(int i=0;i<n;i++)
    {
        dp[i][0]=true;
    }
    if(arr[0]<=sum){
   dp[0][arr[0]]=true;}
   for(int i=1;i<n;i++)
   {
       for(int j=1;j<=sum;j++)
       {
           bool nottake = dp[i-1][j];
           bool take=false;
           if(arr[i]<=j)
           {
               take=dp[i-1][j-arr[i]];
           }
           dp[i][j] = take||nottake;
       }
   }
        return dp[n-1][sum];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends