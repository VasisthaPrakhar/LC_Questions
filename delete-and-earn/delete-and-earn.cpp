class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        int k=*max_element(nums.begin(),nums.end());
        vector<int>a(k+1,0);
        for(int i=0;i<n;i++){
            a[nums[i]]+=nums[i];
        }
        vector<int>dp(k+1);
        dp[0]=0;
        dp[1]=a[1];
        for(int i=2;i<k+1;i++){
            dp[i]=max(dp[i-1],dp[i-2]+a[i]);
        }
        return dp[k];
    }
};