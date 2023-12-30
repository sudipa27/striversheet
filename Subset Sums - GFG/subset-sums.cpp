//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
void func(int ind, vector<int>&arr, vector<int>&ans, int N, int sum)
{
    if(ind==arr.size())
    {
        ans.push_back(sum);
        return;
    }
    //not_take
    func(ind+1,arr,ans,N,sum);
    //take
    func(ind+1,arr,ans,N,sum+arr[ind]);
}
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        func(0,arr,ans,N,0);
        return ans;
        // Write Your Code here
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends