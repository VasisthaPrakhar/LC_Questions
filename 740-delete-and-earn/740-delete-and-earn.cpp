class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int ma=*max_element(nums.begin(),nums.end());
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        vector<int>dp(ma+1,0);
        dp[0]=0;
        if(m.count(1))
        dp[1]=m[1];
        for(int i=2;i<=ma;i++){
            if(m.count(i))
                dp[i]=max(dp[i-1],dp[i-2]+i*m[i]);
            else
                dp[i]=max(dp[i-1],dp[i-2]);
        }
        return dp[ma];
    }
};