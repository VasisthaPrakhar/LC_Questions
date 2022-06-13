// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
	public:
	int MinSquares(int n)
	{
	    // Code here
	    vector<int>a;
	    for(int i=1;i*i<=n;i++){
	        a.push_back(i*i);
	    }
	    int m=a.size();
	    int dp[m+1][n+1];
	    memset(dp,0,sizeof(dp));
	    for(int i=0;i<=n;i++){
	        dp[0][i]=INT_MAX-1;
	    }
	   // for(int i=1;i<=n;i++){
	   //     if(i%a[0]){
	   //         dp[1][i]=INT_MAX-1;
	   //     }else{
	   //         dp[1][i]=i/a[0];
	   //     }
	   // }
	    for(int i=1;i<=m;i++){
	        for(int j=1;j<=n;j++){
	            if(j>=a[i-1]){
	                dp[i][j]=min(dp[i-1][j],1+dp[i][j-a[i-1]]);
	            }else{
	                dp[i][j]=dp[i-1][j];
	            }
	        }
	    }
	    return dp[m][n];
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends