// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int minCoins(int co[], int n, int am) 
	{ 
	    // Your code goes here
	    if(am==0){
            return 0;
        }
        int dp[n+1][am+1];
        for(int i=0;i<=am;i++){
            dp[0][i]=INT_MAX-1;
        }
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        // for(int i=1;i<=am;i++){
        //     if(i%co[0])
        //         dp[1][i]=INT_MAX-1;
        //     else
        //         dp[1][i]=i/co[0];
        // }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=am;j++){
                if(co[i-1]<=j){
                    dp[i][j]=min(dp[i-1][j],1+dp[i][j-co[i-1]]);
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][am]!=INT_MAX-1?dp[n][am]:-1;
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends