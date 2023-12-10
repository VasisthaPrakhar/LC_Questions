class Solution {
public:
    unordered_map<int,unordered_map<int,int>>dp;
    int fun(int idx, vector<int>&p, int n, int prev){
        if(idx>=n){
            return 0;
        }
        if(dp.count(idx)){
            if(dp[idx].count(prev)){
                return dp[idx][prev];
            }
        }
        int res=INT_MAX,res1=INT_MAX;
        if(prev==-1){
            res=p[idx]+fun(idx+1,p,n,idx);
        }else if(idx >= 2*prev+2){
            res=p[idx]+fun(idx+1,p,n,idx);
        }else{
            res=p[idx]+fun(idx+1,p,n,idx);
            res1=fun(idx+1,p,n,prev);
        }
        return dp[idx][prev]=min(res,res1);
    }
    int minimumCoins(vector<int>& p) {
        int n=p.size();
        dp.clear();
        return fun(0,p,n,-1);
    }
};