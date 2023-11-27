class Solution {
public:
    typedef long long int ll;
    ll dp[5001][10];
    int mod = 1e9+7;
    ll fun(int n,int i, map<int,vector<int>>&m){
        if(n==0){
            return 1;
        }
        if(dp[n][i]!=-1){
            return dp[n][i];
        }
        ll res=0;
        for(auto x:m[i]){
            res= (res%mod + fun(n-1,x,m)%mod)%mod;
        }
        return dp[n][i]=res;
    }
    int knightDialer(int n) {
        map<int,vector<int>>m;
        m[0]={4,6};
        m[1]={6,8};
        m[2]={7,9};
        m[3]={4,8};
        m[4]={0,3,9};
        m[5]={};
        m[6]={0,1,7};
        m[7]={2,6};
        m[8]={1,3};
        m[9]={2,4};
        ll ans=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<=9;i++){
            ans = (ans%mod + fun(n-1,i,m)%mod)%mod;
        }
        return ans;
    }
};