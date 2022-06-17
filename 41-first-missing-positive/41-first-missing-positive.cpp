class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(auto &x:nums){
            if(x<=0){
                x=n+1;
            }
        }
        for(int i=0;i<n;i++){
            if(abs(nums[i])<=n && nums[abs(nums[i])-1]>0){
                nums[abs(nums[i])-1]*=-1;   
            }
        }
        for(int i=0;i<n;i++){
            //cout<<nums[i]<<" ";
            if(nums[i]>0){
                return i+1;
            }
        }
        return n+1;
    }
};