class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>res;
        for(int i=0;i<n;i++){
            auto it=lower_bound(res.begin(),res.end(),nums[i]);
            if(it-res.begin()==res.size()){
                res.push_back(nums[i]);
            }else{
                *it=nums[i];
            }
        }
        return res.size();
    }
};