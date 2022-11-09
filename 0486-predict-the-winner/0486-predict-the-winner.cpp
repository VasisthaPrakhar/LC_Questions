class Solution {
public:
    typedef long long int ll;
    ll dp[21][21];
    ll fun(int i,int j,vector<int>&nums,int flag){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        ll res=0;
        if(!flag){
            res=max(nums[i]+fun(i+1,j,nums,1),nums[j]+fun(i,j-1,nums,1));
        }else{
            res=min(-nums[i]+fun(i+1,j,nums,0),-nums[j]+fun(i,j-1,nums,0));
        }
        return dp[i][j]=res;
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=n-1,ans=0;
        memset(dp,-1,sizeof(dp));
        ll res=fun(i,j,nums,ans);
        return res>=0;
    }
};