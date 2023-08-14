//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
    int x=0;
    for(int i=0;i<nums.size();i++)
    {
        x=x^nums[i];
    }
    int set_bit = x&(~(x-1));
    int a=0,b=0;
    for(int i=0;i<nums.size();i++){
        if(set_bit&nums[i])
        {
            a=a^nums[i];
        }
        else
        {
            b=b^nums[i];
        }
    }
    if(a>b)
    {
        return {b,a};
    }
    else
    {
        return {a,b};
    }
        
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends