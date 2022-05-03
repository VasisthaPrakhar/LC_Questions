class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int s=INT_MAX,b=INT_MIN;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                s=min(s,nums[i+1]);
            }
        }
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                b=max(b,nums[i]);
            }
        }
        int p=-1,q=-1;
        for(int i=0;i<n;i++){
            if(nums[i]>s){
                p=i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(nums[i]<b){
                q=i;
                break;
            }
        }
        if(p==-1){
            return 0;
        }
        return q-p+1;
    }
};