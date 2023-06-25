class Solution {
public:
    typedef long long int ll;
    ll mod=1e9+7;
    ll fun(vector<int>& a, int n, int s, int e, int f, vector<vector<int>>&dp){
        if(f<=0){
            if(f==0 && s==e){
                return 1;
            }
            return 0;
        }
        if(dp[s][f]!=-1){
            return dp[s][f];
        }
        ll res=0;
        if(s==e){
            res++;
        }
        for(int i=0;i<n;i++){
            if(i!=s && abs(a[s]-a[i])<=f){
                res = (res%mod + fun(a,n,i,e,f-abs(a[s]-a[i]),dp)%mod)%mod;
            }
        }
        return dp[s][f]=res;
    }
    int countRoutes(vector<int>& a, int s, int e, int f) {
        int n=a.size();
        vector<vector<int>>dp(n+1,vector<int>(f+1,-1));
        return fun(a,n,s,e,f,dp);
    }
};