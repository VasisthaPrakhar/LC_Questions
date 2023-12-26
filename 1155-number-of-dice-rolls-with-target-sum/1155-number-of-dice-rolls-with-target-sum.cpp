typedef long long int ll;
int mod=1e9 + 7;
class Solution {
public:
    int dp[31][1001];
    int fun(int idx,int n,int k,int t){
        if(n<=idx || t<=0){
            return (t==0 && n==idx)?1:0;
        }
        if(dp[idx][t]!=-1){
            return dp[idx][t];
        }
        ll res=0;
        for(int i=1;i<=k;i++){
            res=(res%mod + fun(idx+1,n,k,t-i)%mod)%mod;
        }
        return dp[idx][t]=res%mod;
    }
    int numRollsToTarget(int n, int k, int t) {
        memset(dp,-1,sizeof(dp));
        return fun(0,n,k,t);
    }
};