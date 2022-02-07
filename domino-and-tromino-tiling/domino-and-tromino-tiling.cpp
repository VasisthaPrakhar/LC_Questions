class Solution {
    #define mod 1000000007
public:
    int dp(vector<vector<int>>&memo,int n,int e){
        if(n<=1){
            return e==2?1:0;
        }
        if(memo[n][e]==-1){
            int res=0;
            if(e==2){
                res=(res+dp(memo,n-1,2)%mod)%mod;
                res=(res+dp(memo,n-2,2)%mod)%mod;
                res=(res+(2*dp(memo,n-1,1))%mod)%mod;
            }
            else{
                res=(res+dp(memo,n-1,1)%mod)%mod;
                res=(res+dp(memo,n-2,2)%mod)%mod;
            }
            memo[n][e]=res;
        }
        return memo[n][e];
    }
    int numTilings(int n) {
        vector<vector<int>>memo(n+1,vector<int>(3,-1));
        return dp(memo,n,2);
    }
};