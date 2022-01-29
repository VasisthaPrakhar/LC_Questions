class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int k=abs(nums[i])-1;
            nums[k]*=-1;
            if(nums[k]>0){
                ans=k+1;
                break;
            }
        }
        return ans;
    }
};