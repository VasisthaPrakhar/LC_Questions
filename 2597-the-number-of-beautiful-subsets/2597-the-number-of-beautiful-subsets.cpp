class Solution {
public:
    
    int fun(int idx,int n,vector<int>&nums,int k,unordered_map<int,int>&a){
        if(idx>=n){
            if(!a.empty())
                return 1;
            return 0;
        }
        int res=0;
        if(a.find(nums[idx]+k)==a.end() && a.find(nums[idx]-k)==a.end()){
            a[nums[idx]]++;
            res+=fun(idx+1,n,nums,k,a);
            a[nums[idx]]--;
            if(a[nums[idx]]==0){
                a.erase(nums[idx]);
            }
        }
        res +=fun(idx+1,n,nums,k,a);
        return res;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>m;
        return fun(0,n,nums,k,m);
    }
};