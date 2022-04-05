class Solution {
public:
    set<vector<int>>ans;
    void fun(vector<int>&a ,int idx, vector<int>&res,int &n){
        if(idx==n){
            if(res.size()>1)
                ans.insert(res);
            return;
        }
        if(res.size()>1)
                ans.insert(res);
        if(a[idx]>=res.back()){
            res.push_back(a[idx]);
            fun(a,idx+1,res,n);
            res.pop_back();
        }
        fun(a,idx+1,res,n);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n=nums.size();
        vector<int>res;
        for(int i=0;i<n;i++){
            res.push_back(nums[i]);
            fun(nums,i+1,res,n);
            res.pop_back();
        }
        vector<vector<int>>ans1(ans.begin(),ans.end());
        return ans1;
    }
};