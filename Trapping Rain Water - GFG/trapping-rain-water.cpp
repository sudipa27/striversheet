//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        vector<int> leftMax;
        vector<int> rightMax;
        int maxi=arr[0];
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,arr[i]);
            leftMax.push_back(maxi);
        }
         maxi=arr[n-1];
        for(int i=n-1;i>=0;i--)
        {
            maxi=max(maxi,arr[i]);
            rightMax.push_back(maxi);
        }
        reverse(rightMax.begin(),rightMax.end());
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=min(leftMax[i],rightMax[i])-arr[i];
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends