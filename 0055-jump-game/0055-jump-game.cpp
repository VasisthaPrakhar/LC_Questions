class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i=0,end=0,n=nums.size();
        for(i=0;i<=end;i++){
            end=end>i+nums[i]?end:i+nums[i];
            if(end>=n-1){
                return true;
            }
        }
        return false;
    }
};