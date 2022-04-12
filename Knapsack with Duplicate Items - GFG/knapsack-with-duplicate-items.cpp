// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[1001][1001]; 
    int fun(int n, int w, int val[], int wt[]){
        if(w>=0 && n<0){
            return 0;
        }
        if(w<0){
            return INT_MIN;
        }
        if(dp[n][w]==-1){
            int a=val[n]+fun(n-1,w-wt[n],val,wt);
            int b=val[n]+fun(n,w-wt[n],val,wt);
            int c=fun(n-1,w,val,wt);
            dp[n][w]=max(a,max(b,c));
        }
        return dp[n][w];
    }
    int knapSack(int n, int w, int val[], int wt[])
    {
        // code here
         memset(dp,-1,sizeof dp);
        return fun(n-1,w,val,wt);
    }
        
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends