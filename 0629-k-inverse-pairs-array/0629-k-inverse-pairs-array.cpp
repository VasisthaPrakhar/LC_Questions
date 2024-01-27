class Solution {
public:
    typedef long long int ll;
    int dp[1001][1001];
    int mod=1e9 + 7;
    int fun(int n, int k){
        if(k==0){
            return 1;
        }
        if(dp[n][k]!=-1){return dp[n][k];}
        ll res=0;
        for(int i=0;i<n;i++){
            if(k-i>=0){
                res = (res%mod + fun(n-1,k-i)%mod)%mod;
            }else{
                break;
            }
        }
        return dp[n][k]=res%mod;
    }
    int kInversePairs(int n, int k) {
        memset(dp,-1,sizeof(dp));
        return fun(n,k);
    }
};