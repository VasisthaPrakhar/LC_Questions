//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    typedef long long int ll;
  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    ll sum=0;
	    for(int i=0;i<n;i++){
	        sum+=arr[i];
	    }
	    ll k=sum;
	    sum/=2;
	    bool dp[n+1][sum+1];
	    memset(dp,false,sizeof(dp));
	    for(int i=0;i<=n;i++){
	        dp[i][0]=true;
	    }
	    for(int i=1;i<=n;i++){
	        for(int j=0;j<=sum;j++){
	            if(j-arr[i-1]>=0){
	                dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
	            }else{
	                dp[i][j]=dp[i-1][j];
	            }
	        }
	    }
	    ll ans=0;
	    for(int i=sum;i>=0;i--){
	        if(dp[n][i]){
	            ans= k-2*i;
	            break;
	        }
	    }
	    return ans;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends