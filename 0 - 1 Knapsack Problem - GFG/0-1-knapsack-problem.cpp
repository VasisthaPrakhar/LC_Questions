// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    // int memo[1001][1001];
    // int dp(int W, int wt[], int val[], int n){
    //     if(W<0 || n==0){
    //         return 0;
    //     }
    //     if(memo[W][n]==-1){
    //         if(wt[n-1]<=W){
    //             memo[W][n]=max(val[n-1]+dp(W-wt[n-1],wt,val,n-1),dp(W,wt,val,n-1));
    //         }else{
    //             memo[W][n]=dp(W,wt,val,n-1);
    //         }
    //     }
    //     return memo[W][n];
    // }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       int dp[n+1][W+1];
       for(int i=0;i<=n;i++){
           dp[i][0]=0;
       }
       for(int i=0;i<=W;i++){
           dp[0][i]=0;
       }
       for(int i=1;i<=n;i++){
           for(int j=1;j<=W;j++){
               if(wt[i-1]<=j){
                   dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
               }else{
                   dp[i][j]=dp[i-1][j];
               }
           }
       }
       //memset(memo,-1,sizeof(memo));
       return dp[n][W];
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends