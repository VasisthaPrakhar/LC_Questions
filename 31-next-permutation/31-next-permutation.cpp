class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int j=n-2,k=j+1;
        while(j>=0 && nums[k]<=nums[j]){
            k--;
            j--;
        }
        if(j==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        int i;
        for(i=n-1;i>j;i--){
            if(nums[i]>nums[j]){
                break;
            }
        }
        swap(nums[i],nums[j]);
        reverse(nums.begin()+k,nums.end());
    }
};