class Solution {
public:
    typedef long long int ll;
    int dp[201][201];
    ll fun(int curr,int d,int n,int k,vector<vector<int>>&ss,vector<vector<int>>&ts){
        if(d>=k){
            return 0;
        }
        if(dp[curr][d]!=-1){
            return dp[curr][d];
        }
        ll res=0;
        res=max(res,ss[d][curr]+fun(curr,d+1,n,k,ss,ts));
        for(int i=0;i<n;i++){
            if(i!=curr)
                res=max(res,ts[curr][i]+fun(i,d+1,n,k,ss,ts));
        }
        return dp[curr][d]=res;
    }
    int maxScore(int n, int k, vector<vector<int>>& ss, vector<vector<int>>& ts) {
        ll ans=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            ans=max(ans,fun(i,0,n,k,ss,ts));
        }
        return ans;
    }
};