class Solution {
public:
    int mod=1e9+7;
    typedef long long int ll;
    int dp[100001][3][2];
    int fun(int idx,int n,int b,int a){
        if(idx>=n){
            return 1;
        }
        if(dp[idx][b][a]!=-1){
            return dp[idx][b][a];
        }
        ll res=0;
        if(a>0){
            res = (res%mod+fun(idx+1,n,0,a-1)%mod)%mod;
        }
        if(b<2){
            res = (res%mod+fun(idx+1,n,b+1,a)%mod)%mod;
        }
        res = (res%mod+fun(idx+1,n,0,a)%mod)%mod;
        return dp[idx][b][a]=res%mod;
    }
    int checkRecord(int n) {
        memset(dp,-1,sizeof(dp));
        return fun(0,n,0,1);
    }
};