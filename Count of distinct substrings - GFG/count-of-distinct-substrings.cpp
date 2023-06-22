//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int countDistinctSubstring(string s);

int main()
{
 int t,l,i,j;
 int temp;
    cin>>t;
 while(t--){
 string s;
  cin>>s;
  cout<<countDistinctSubstring(s)<<endl;

 }
}


// } Driver Code Ends


/*You are required to complete this method */
struct Node{
    Node* links[26];
    bool containKeys(char ch)
    {
        return (links[ch-'a']!=NULL);
    }
    Node* get(char ch)
    {
        return links[ch-'a'];
    }
    void put(char ch, Node* node)
    {
        links[ch-'a']=node;
    }
};
int countDistinctSubstring(string s)
{
    int n=s.size();
    Node* root= new Node();
    int count =0;
    for(int i=0;i<n;i++)
    {
        Node* node= root;
        for(int j=i;j<n;j++)
        {
            if(!node->containKeys(s[j]))
            {
               node->put(s[j],new Node());
                count++;
            }
            node=node->get(s[j]);
        }
    }
    return count+1;
}