static const auto Initialize = []{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int n;
    unordered_map<int,vector<int>>m;
    vector<int> fun(vector<int>& nums, int beg){
        if(beg>=n){
            return {};
        }
        if(m.count(beg)){
            return m[beg];
        }
        for(int i=beg+1;i<n;i++){
            if(nums[i]%nums[beg]!=0){
                continue;
            }
            vector<int>ma=fun(nums,i);
            if(ma.size()>m[beg].size()){
                m[beg]=ma;
            }
        }
        m[beg].push_back(nums[beg]);
        return m[beg];
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>ans;
        for(int i=0;i<n;i++){
            vector<int>ma=fun(nums,i);
            if(ma.size()>ans.size()){
                ans=ma;
            }
        }
        return ans;
    }
};