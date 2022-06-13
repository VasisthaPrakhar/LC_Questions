class Solution {
public:
    int combinationSum4(vector<int>& nums, int t) {
        int n=nums.size();
        unsigned long long int dp[t+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=1;i<=t;i++){
            for(int j=0;j<n;j++){
                if(i>=nums[j]){
                    dp[i]+=dp[i-nums[j]];
                }
            }
        }
        return dp[t];
    }
};