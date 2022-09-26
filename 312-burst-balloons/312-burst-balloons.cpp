class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        int dp[n+2][n+2];
        memset(dp,0,sizeof(dp));
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);
        for(int i=n;i>0;i--){
            for(int j=i;j<=n;j++){
                int ma=INT_MIN;
                for(int idx=i;idx<=j;idx++){
                    ma=max(ma,nums[i-1]*nums[idx]*nums[j+1] + dp[idx+1][j] + dp[i][idx-1]);
                }
                dp[i][j]=ma;
            }
        }
        return dp[1][n];
    }
};