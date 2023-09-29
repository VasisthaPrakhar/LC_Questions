class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n=nums.size(),f=0;
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i]){
                f=1;
                break;
            }
        }
        if(!f){
            return true;
        }
        for(int i=1;i<n;i++){
            if(nums[i-1]<nums[i]){
                return false;
            }
        }
        return true;
    }
};