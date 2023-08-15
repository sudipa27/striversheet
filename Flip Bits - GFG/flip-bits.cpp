//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxOnes(int a[], int n)
    {
        // Your code goes here
        vector<int> marr;
       int oneCount=0;
       int first=0,last=0;
       for(int i=0;i<n;i++)
       {
          if(a[i]==1)
          {
              oneCount++;
              marr.push_back(-1);
          }
          else
          {
              marr.push_back(1);
          }
       }
       if(oneCount==n)
       {
           return n;
       }
       int sum=0;
       int maxi=INT_MIN;
       for(int i=0;i<marr.size();i++)
       {
           sum+=marr[i];
           maxi=max(maxi,sum);
           if(sum<0)
           {
               sum=0;
           }
           
       }
       return maxi+oneCount;
     
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends