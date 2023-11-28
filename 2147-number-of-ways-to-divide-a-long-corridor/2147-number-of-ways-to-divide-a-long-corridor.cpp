class Solution {
public:
    int mod=1e9 + 7;
    typedef long long int ll;
    ll fun(int idx, string &s, int c, int n, vector<vector<ll>>&dp){
        if(idx>=n){
            if(c==2){
                return 1;
            }
            return 0;
        }
        if(dp[idx][c]!=-1){
            return dp[idx][c];
        }
        ll res=0;
        int k=c;
        if(s[idx]=='S'){
            k++;
        }
        if(k==2){
            res= (res%mod + fun(idx+1,s,0,n,dp)%mod)%mod;
        }
        if(k<=2){
            res = (res%mod + fun(idx+1,s,k,n,dp)%mod)%mod;   
        }
        return dp[idx][c]=res%mod;
    }
    int numberOfWays(string c) {
        int n=c.length();
        vector<vector<ll>>dp(n+1,vector<ll>(3,-1));
        return fun(0,c,0,n,dp);
    }
};