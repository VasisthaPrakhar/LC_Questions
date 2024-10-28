class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int dp[100001];
        memset(dp,0,sizeof(dp));
        int ans=0;
        set<int>s;
        for(int i=0;i<n;i++){
            int k=sqrt(nums[i]);
            if(k*k == nums[i] && s.find(k)!=s.end()){
                dp[nums[i]]=1+dp[k];
                ans=max(dp[nums[i]],ans);
            }
            s.insert(nums[i]);
        }
        return ans==0?-1:ans+1;
    }
};