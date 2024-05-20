class Solution {
public:
    void fun(int idx,int n,vector<int>&nums,int k,int &ans){
        if(idx>=n){
           ans+=k;
           return;
        }
        fun(idx+1,n,nums,k,ans);
        fun(idx+1,n,nums,k^nums[idx],ans);
    }
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size(),k=0,ans=0;
        fun(0,n,nums,k,ans);
        return ans;
    }
};