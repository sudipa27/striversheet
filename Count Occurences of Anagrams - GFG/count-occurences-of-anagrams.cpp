//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
bool AllZero(vector<int>&count)
{
    for(int i=0;i<count.size();i++)
    {
        if(count[i]!=0)
        {
            return false;
        }
    }
    return true;
}
	int search(string pat, string txt) {
	   int n= txt.size();
	   vector<int> counter(26,0);
	   for(int i=0;i<pat.size();i++)
	   {
	       counter[pat[i]-'a']++;
	   }
	   int i=0,j=0,ans=0;
	   while(j<n)
	   {
	       counter[txt[j]-'a']--;
	       if(j-i+1==pat.size())
	       {
	           if(AllZero(counter))
	           {
	               ans++;
	               
	           }
	           counter[txt[i]-'a']++;
	           i++;
	       }
	       j++;
	   }
	   return ans;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends