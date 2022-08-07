class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int l, int r) {
        long long int ans=0;
        int n=nums.size();
        if(n==1){
            if(l<=nums[0] && r>=nums[0]){
                return 1;
            }
            return 0;
        }
        int j=0,left=-1,right=-1;
        while(j<n){
            if(nums[j]>=l){
                right=j;
            }
            if(nums[j]>r){
                left=j;
            }
            ans+=right-left;
            j++;
        }
        return ans;
        
    }
};