class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<3){
            return 0;
        }
        int i=0,j=2,ans=0;
        int diff=nums[1]-nums[0];
        while(j<n){
            if(nums[j]-nums[j-1]==diff){
                ans+=j-i-1;
            }else{
                diff=nums[j]-nums[j-1];
                i=j-1;
            }
            j++;
        }
        return ans;
    }
};