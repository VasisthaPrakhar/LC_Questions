#pragma GCC optimize("fast")
static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>dp(1005,INT_MAX);
        for(int idx=0;idx<n;idx++){
            unordered_map<int,int>m;
            int z=0;
            for(int i=idx;i>=0;i--){
                m[nums[i]]++;
                if(m[nums[i]]>1){
                    if(m[nums[i]]==2){
                        z+=2;
                    }else{
                        z++;
                    }
                }
                dp[idx]=min(dp[idx],k+z+(i==0?0:dp[i-1]));
            }
        }
        return dp[n-1];
        
    }
};