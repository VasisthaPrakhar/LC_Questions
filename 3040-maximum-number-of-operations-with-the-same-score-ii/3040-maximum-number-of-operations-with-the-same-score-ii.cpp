class Solution {
public:
    unordered_map<int,unordered_map<int,map<int,int>>>dp;
    int fun(vector<int>&nums, int i,int j,int prev){
        if(j-i<1){
            return 0;
        }
        if(dp.count(i)){
            if(dp[i].count(j)){
                if(dp[i][j].count(prev)){
                    return dp[i][j][prev];
                }
            }
        }
        int res=0;
        if(prev==-1){
            res=max(res,1+fun(nums,i+2,j,nums[i]+nums[i+1]));
            res=max(res,1+fun(nums,i,j-2,nums[j]+nums[j-1]));
            res=max(res,1+fun(nums,i+1,j-1,nums[i]+nums[j]));
        }else{
            if(prev ==nums[i]+nums[i+1]){
                res=max(res,1+fun(nums,i+2,j,prev));
            }
            if(prev ==nums[j]+nums[j-1]){
                res=max(res,1+fun(nums,i,j-2,prev));
            } 
            if(prev == nums[i]+nums[j]){
                res=max(res,1+fun(nums,i+1,j-1,prev));
            }
        }
        return dp[i][j][prev]=res;
    }
    int maxOperations(vector<int>& nums) {
        int n=nums.size();
        dp.clear();
        return fun(nums,0,n-1,-1);
    }
};