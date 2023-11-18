class Solution {
public:
    int mod=1e9+7;
    typedef long long int ll;
    int dp[100001][2][3][2];
    ll fun(int idx,int n,int l,int e,int t){
        if(idx>n){
            if(l>=1 && e>=2 && t>=1){
                return 1;
            }
            return 0;
        }
        if(dp[idx][l][e][t]!=-1){
            return dp[idx][l][e][t];
        }
        ll res=0;
        for(int i=0;i<26;i++){
            if(i==4 && e<2){
                res = (res%mod + fun(idx+1,n,l,e+1,t)%mod)%mod;
            }else if(i==11 && l<1){
                res = (res%mod + fun(idx+1,n,l+1,e,t)%mod)%mod;
            }else if(i==19 && t<1){
                res = (res%mod + fun(idx+1,n,l,e,t+1)%mod)%mod;
            }else{
                res = (res%mod + fun(idx+1,n,l,e,t)%mod)%mod;
            }
        }
        return dp[idx][l][e][t]=res;
    }
    int stringCount(int n) {
        if(n<4){return 0;}
        memset(dp,-1,sizeof(dp));
        return fun(1,n,0,0,0)%mod;
    }
};