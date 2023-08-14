//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{     
  string st="";
  int i=0,j=0;
  int cnt=0;
  while(j<src.size())
  {
      if(src[i]==src[j]){
      cnt++;
      j++;
      if(j==src.size())
      {
          st+=src[i]+to_string(cnt);
      }}
      else
      {
          st+=src[i]+to_string(cnt);
          cnt=0;
          i=j;
      }
  }
  return st;
}     
 
