class Solution {
public:
    int combinationSum4(vector<int>& nums, int t) {
        int n=nums.size();
        unsigned long long int dp[t+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int j=1;j<=t;j++){
            for(auto x:nums){
                if(j>=x){
                    dp[j]+=dp[j-x];
                }
            }
        }
        return dp[t];
    }
};