class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int l=-1,r=-1,n=nums.size();
        int mi=INT_MAX,ma=INT_MIN;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                mi=min(mi,nums[i+1]);
                ma=max(ma,nums[i]);
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]>mi){
                l=i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(nums[i]<ma){
                r=i;
                break;
            }
        }
        if(l==-1){
            return 0;
        }
        return r-l+1;
    }
};