// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int fun(int W, int wt[], int val[], int n, vector<vector<int>>&memo){
         if(n==0 || W==0){
           return 0;
       }
       if(memo[W][n]>=0){
           return memo[W][n];
       }
       if(wt[n-1]>W){
            memo[W][n]=fun(W,wt,val,n-1,memo);
       }else{
            memo[W][n]=max(fun(W,wt,val,n-1,memo),val[n-1]+fun(W-wt[n-1],wt,val,n-1,memo));
       }
       return memo[W][n];
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
      vector<vector<int>>memo(W+1,vector<int>(n+1,-1));
      return fun(W,wt,val,n,memo);
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