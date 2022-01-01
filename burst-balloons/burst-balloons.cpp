class Solution {
    private:
    int dp[502][502];
    int mcm(vector<int>&nums, int i,int j)
    {
        if(i>=j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=INT_MIN;
        for(int k=i;k<=j-1;k++)
        {
            int tempans=mcm(nums,i,k)+mcm(nums,k+1,j)+nums[i-1]*nums[k]*nums[j];
            ans=max(ans,tempans);
        }
        return dp[i][j]=ans;
    }
    
public:
    int maxCoins(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);
        return mcm(nums,1,nums.size()-1);
    }
};