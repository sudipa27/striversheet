//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    struct meeting 
    {
        int start;
        int end;
        int pos;
    };
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool cmp(meeting a, meeting b)
    {
        if(a.end<b.end)
        {
            return true;
        }
        else if(a.end>b.end)
        {
            return false;
        }
        else if(a.pos<b.pos)
        {
            return true;
        }
        return false;
    }
    int maxMeetings(int start[], int end[], int n)
    {
    struct meeting meet[n];
    for(int i=0;i<n;i++)
    {
        meet[i].start=start[i];
        meet[i].end = end[i];
        meet[i].pos=i+1;
    }
    sort(meet,meet+n,cmp);
    vector<int> ans;
    int limit = meet[0].end;
    ans.push_back(meet[0].pos);
    for(int i=0;i<n;i++)
    {
        if(meet[i].start > limit)
        {
            limit = meet[i].end;
            ans.push_back(meet[i].pos);
        }
    }
    return ans.size();
        // Your code here
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends