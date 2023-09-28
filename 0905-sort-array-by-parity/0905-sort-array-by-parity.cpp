class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        int j=0,k=n-1;
        for(int i=0;i<n;i++){
            if(nums[i]%2){
                ans[k--]=nums[i];
            }else{
                ans[j++]=nums[i];
            }
        }
        return ans;
    }
};