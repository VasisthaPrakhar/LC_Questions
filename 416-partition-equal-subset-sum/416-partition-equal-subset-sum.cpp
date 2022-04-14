#pragma GCC optimize("fast")
static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto &x:nums){
            sum+=x;
        }
        if(sum%2==0){
            sum=sum/2;
            int n=nums.size();
            bool dp[n+1][sum+1];
            for(int i=0;i<=sum;i++){
                dp[0][i]=false;
            }
            for(int i=0;i<=n;i++){
                dp[i][0]=true;
            }
            for(int i=1;i<=n;i++){
                for(int j=1;j<=sum;j++){
                    if(j>=nums[i-1]){
                        dp[i][j]=dp[i-1][j-nums[i-1]]||dp[i-1][j];
                    }else{
                        dp[i][j]=dp[i-1][j];
                    }
                }
            }
            return dp[n][sum];
        }
        return false;
    }
};