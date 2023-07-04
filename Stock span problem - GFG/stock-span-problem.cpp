//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       stack<int> st;
       vector<int> vec;
       vector<int> ans;
       for(int i=0;i<n;i++)
       {
           while(!st.empty() && price[st.top()]<=price[i])
           {
               st.pop();
           }
           if(st.empty())
           {
               vec.push_back(-1);
           }
           else if(price[st.top()]>price[i])
           {
               vec.push_back(st.top());
           }
           st.push(i);
       }
       for(int i=0;i<n;i++)
       {
           ans.push_back(i-vec[i]);
       }
       return ans;
       
    }
};



//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends