class Solution {
public:
    int minSubArrayLen(int k, vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0,ans=INT_MAX,sum=0;
        while(j<n){
            sum+=nums[j];
            while(i<=j && sum>=k){
                ans=min(ans,j-i+1);
                sum-=nums[i];
                i++;
            }
            j++;
        }
        return ans==INT_MAX?0:ans;
    }
};