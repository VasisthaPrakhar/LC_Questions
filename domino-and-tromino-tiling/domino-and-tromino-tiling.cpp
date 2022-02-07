class Solution {
    #define mod 1000000007
public:
    int dp(vector<int>&memo,int n){
        if(n<=1){
            return n==0?1:0;
        }
        if(memo[n]==-1){
            memo[n]=((2*dp(memo,n-1))%mod + dp(memo,n-3)%mod)%mod;
        }
        return memo[n];
    }
    int numTilings(int n) {
        if(n<=2){
            return n;
        }
        vector<int>memo(n+1,-1);
        for(int i=0;i<3;i++){
            memo[i]=i;
        }
        memo[3]=5;
        for(int i=4;i<=n;i++){
            memo[i]=((2*memo[i-1])%mod + memo[i-3]%mod)%mod;
        }
        return memo[n];
    }
};