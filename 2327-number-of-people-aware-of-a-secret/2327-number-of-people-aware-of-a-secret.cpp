class Solution {
public:
    int mod=1e9 + 7;
    int peopleAwareOfSecret(int n, int d, int f) {
        vector<long long int>dp(n,0),a(n,0);
        dp[0]=1;
        a[0]=1;
        for(int i=1;i<n;i++){
            if(i-f>=0){
                for(int j=i-f;j<=i-1;j++){
                    dp[j]=((dp[j]%mod - a[i-f]%mod)+mod)%mod;
                }
            }
            dp[i]= ((dp[i]%mod + dp[i-1]%mod)+mod)%mod;
            if(i-d>=0){
                dp[i]=((dp[i]%mod + dp[i-d]%mod)+mod)%mod;
                a[i]=dp[i-d]%mod;
            }
            cout<<i+1<<" "<<dp[i]<<" "<<a[i]<<endl;
        }
        return dp[n-1]<0?0:dp[n-1];
    }
};