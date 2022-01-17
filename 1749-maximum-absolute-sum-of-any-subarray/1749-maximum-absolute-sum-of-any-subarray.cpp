class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();
        int sum=0,ans1=INT_MIN,ans2=INT_MAX;
        for(int i=0;i<n;i++){
            sum=max(sum+nums[i],nums[i]);
            ans1=max(ans1,sum);
        }
        sum=0;
        for(int i=0;i<n;i++){
            sum=min(sum+nums[i],nums[i]);
            ans2=min(ans2,sum);
        }
        return max(abs(ans1),abs(ans2));
    }
};