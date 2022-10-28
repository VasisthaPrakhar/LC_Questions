//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
typedef long long int ll;
class Solution {
	public:
	    int mod=1000000007;
		int NthTerm(int n){
		    // Code  here
		    if(n==1){
		        return 2;
		    }
		    ll k=NthTerm(n-1)%mod;
		    return ((k*(ll)n%mod)%mod + 1LL)%mod;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution obj;
		int ans = obj.NthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends