//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    typedef long long int ll;
    ll mod=1e9 + 7;
    int totalWays(int n, vector<int>cp) {
        // code here
        sort(cp.begin(),cp.end());
        ll k=cp[0];
        for(int i=1;i<n;i++){
            k=(k%mod * (ll)(cp[i]-i)%mod)%mod;
        }
        return k%mod;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>capacity(n);
		for(int i = 0; i < n; i++)
			cin >> capacity[i];
		Solution ob;
		int ans = ob.totalWays(n, capacity);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends