class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int s=0,w=0;
        for(auto x:nums){
            s+=x;
        }
        if(s<abs(target) || (s+target)%2!=0){
            return 0;
        }
        w=(s+target)/2;
        int dp[n+1][w+1];
        memset(dp,0,sizeof(dp));
        // for(int i=0;i<=n;i++){
        //     dp[i][0]=1;
        // }
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=w;j++){
                if(nums[i-1]<=j){
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-nums[i-1]];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][w];
    }
};
