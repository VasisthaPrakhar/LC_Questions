class Solution {
public:
    set<vector<int>>s;
    void dp(int n,int idx,int prev,vector<int>&a,vector<int>&nums){
        if(idx>n){
            return;
        }
        if(a.size()>=2){
            s.insert(a);
        }
        // for(auto x:a){
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        for(int i=idx;i<n;i++){
            if(nums[i]>=prev){
                a.push_back(nums[i]);
                dp(n,i+1,nums[i],a,nums);
                a.pop_back();
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>a;
        dp(n,0,-101,a,nums);
        for(auto x:s){
            ans.push_back(x);
        }
        return ans;
    }
};