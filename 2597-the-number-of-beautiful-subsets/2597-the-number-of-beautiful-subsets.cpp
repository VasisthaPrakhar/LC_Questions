class Solution {
public:
    unordered_map<int,map<vector<int>,int>>dp;
    int fun(int idx,int n,vector<int>&nums,int k,vector<int>&a){
        if(idx>=n){
            return 1;
        }
        int res=0;
        if((a[nums[idx]+k]==0 && (nums[idx]-k)<0) || (a[nums[idx]+k]==0 && a[nums[idx]-k]==0)){
            a[nums[idx]]++;
            res+=fun(idx+1,n,nums,k,a);
            a[nums[idx]]--;
        }
        res +=fun(idx+1,n,nums,k,a);
        return res;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>a(2002,0);
        dp.clear();
        return fun(0,n,nums,k,a)-1;
    }
};