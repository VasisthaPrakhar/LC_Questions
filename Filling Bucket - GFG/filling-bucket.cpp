//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    typedef long long int ll;
  public:
    int mod=1e8;
    int fun(int n,vector<int>&dp){
        if(n==0){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        ll res=0;
        if(n>1){
            res= res%mod + fun(n-1,dp)%mod;
            res= res%mod + fun(n-2,dp)%mod;
        }else{
            res= res%mod + fun(n-1,dp)%mod;
        }
        return dp[n]=res%mod;
    }
    int fillingBucket(int n) {
        // code here
        vector<int>dp(n+1,-1);
        return fun(n,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends