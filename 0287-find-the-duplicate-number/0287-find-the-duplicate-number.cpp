class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int k=abs(nums[i])-1;
            nums[k]=nums[k]*-1;
            if(nums[k]>0){
                return k+1;
            }
        }
        return 0;
    }
};