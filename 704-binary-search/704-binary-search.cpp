class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto it=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(it<nums.size() && nums[it]==target){
            return it;
        }
        return -1;
    }
};