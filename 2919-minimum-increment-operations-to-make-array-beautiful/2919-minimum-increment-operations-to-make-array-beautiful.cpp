class Solution {
public:
    typedef long long int ll;
    long long minIncrementOperations(vector<int>& nums, int k) {
        int n=nums.size();
        vector<ll>dp(n,0);
        dp[0]=max(0,k-nums[0]);
        dp[1]=max(0,k-nums[1]);
        dp[2]=max(0,k-nums[2]);
        for(int i=3;i<n;i++){
            dp[i]=max(0,k-nums[i])+min({dp[i-1],dp[i-2],dp[i-3]});
        }
        return min({dp[n-1],dp[n-2],dp[n-3]});
    }
};