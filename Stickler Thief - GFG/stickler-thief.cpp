//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int func(int arr[], int ind, vector<int> &dp)
    {
        if(ind==0)
        {
            return 0;
        }
        if(dp[ind]!=-1)
        {
            return dp[ind];
        }
        int take = arr[ind]+func(arr,ind-2,dp);
        int nottake = func(arr,ind-1,dp);
        return dp[ind]=max(take,nottake);
    }
    int FindMaxSum(int arr[], int n)
    {
        vector<int> dp(n,-1);
       /* dp[0]=arr[0];
        for(int i=1;i<n;i++)
        {
            int take = arr[i] ;
            if(i-2 >=0)
            {
                take+= dp[i-2];
            }
            int nottake = dp[i-1];
            dp[i]=max(take,nottake);
        }
        return dp[n-1];*/
        int prev=arr[0];
        int prev2=0,curr=0;
        for(int i=1;i<n;i++)
        {
            int take = arr[i];
            if(i>1)
            {
                take+=prev2;
            }
            int nottake = 0 + prev;
            int curri = max(take,nottake);
            prev2=prev;
            prev=curri;
        }
        return prev;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends