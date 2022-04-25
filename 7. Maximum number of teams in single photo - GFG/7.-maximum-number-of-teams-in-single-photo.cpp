// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    int maximumNumberOfTeams(vector<int> &teams)
    {
        // code here
        set<int>s(teams.begin(),teams.end());
        return s.size();
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        
        Solution ob;
        int ans = ob.maximumNumberOfTeams(arr);
        cout << ans;
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends