class Solution {
public:
    bool canJump(vector<int>& nums) {
        int end=0,n=nums.size();
        for(int i=0;i<=end;i++){
            end=max(i+nums[i],end);
            if(end>=n-1){
                return true;
            }
        }
        return false;
    }
};