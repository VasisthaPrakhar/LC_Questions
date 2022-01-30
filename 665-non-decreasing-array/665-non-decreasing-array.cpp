class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int c=0,prev=0,n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[prev]>nums[i]){
                if(c++>0){
                    return false;
                }
                if (i - 2 >= 0 && nums[i - 2] > nums[i]) continue;
            }
            prev=i;
        }
        return true;
    }
};