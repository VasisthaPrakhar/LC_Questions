class Solution {
public:
    int combinationSum4(vector<int>& nums, int t) {
        unsigned long long int dp[t+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=1;i<=t;i++){
            for(auto x:nums){
                if(i>=x)
                    dp[i]+=dp[i-x];
            }
        }
        return dp[t];
    }
};