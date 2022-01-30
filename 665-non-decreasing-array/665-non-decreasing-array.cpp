class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int c=0,prev=0,n=nums.size();
        if(n < 3)
        {
            return true;
        }
        for(int i=1;i<n;i++){
            if(nums[prev]>nums[i]){
                c++;
                if(c>1){
                    return false;
                }
                if (i - 2 >= 0 && nums[i - 2] > nums[i]) continue;
            }
            prev=i;
        }
        return true;
    }
};