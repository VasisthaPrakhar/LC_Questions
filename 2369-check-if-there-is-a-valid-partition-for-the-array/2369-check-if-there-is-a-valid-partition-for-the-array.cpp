class Solution {
public:
    bool fun(int idx, int n, vector<int>&a, vector<int>&dp){
        if(idx>=n){
            return true;
        }
        if(dp[idx]!=-1){
            return dp[idx]; 
        }
        bool res=false;
        if(idx<n-1 && a[idx]==a[idx+1]){
            res|=fun(idx+2,n,a,dp);
            if(idx<n-2 && a[idx]==a[idx+2]){
                res|=fun(idx+3,n,a,dp);
            }
        }
        if(idx<n-2 && a[idx]+1==a[idx+1] && a[idx+1]+1==a[idx+2]){
            res|=fun(idx+3,n,a,dp);
        }
        return dp[idx]=res;
    }
    bool validPartition(vector<int>& a) {
        int n=a.size();
        vector<int>dp(n+1,-1);
        return fun(0,n,a,dp);
    }
};