// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    // bool dp(int W,vector<int>&arr,int n){
    //     if(n==0){
    //         return false;
    //     }
    //     if(W==0){
    //         return true;
    //     }
    //     if(arr[n-1]<=W){
    //         return dp(W-arr[n-1],arr,n-1)|| dp(W,arr,n-1);
    //     }else{
    //         return dp(W,arr,n-1)
    //     }
    // }
    bool isSubsetSum(vector<int>&arr, int sum){
        // code here;
        int n=arr.size();
        bool dp[n+1][sum+1];
        for(int i=0;i<=sum;i++){
            dp[0][i]=false;
        }
        for(int i=0;i<=n;i++){
            dp[i][0]=true;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(arr[i-1]<=j){
                    dp[i][j]=dp[i-1][j-arr[i-1]]||dp[i-1][j];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends