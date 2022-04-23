// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    int gcd(int a,int b){
        if(b==0){
            return a;
        }
        return gcd(b,a%b);
    }
    long long int lcm(vector<int> a,int n){
        long long int ans=a[0];
        for(int i=1;i<n;i++){
            ans=a[i]*ans / gcd(a[i],ans);
        }
        return ans;
    }
    string lcmT(int n, int m, vector<int> &arr1, vector<int> &arr2)
    {
        // code here
        if(lcm(arr1,n)==lcm(arr2,m)){
            return "YES";
        }
        return "NO";
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> arr1(n), arr2(m);
        for (int i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }

        for (int i = 0; i < m; i++)
        {
            cin >> arr2[i];
        }
        Solution ob;
        string ans = ob.lcmT(n, m, arr1, arr2);
        cout << ans;
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends