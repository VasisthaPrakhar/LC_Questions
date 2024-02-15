class Solution {
public:
    typedef long long int ll;
    long long largestPerimeter(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        ll sum=0,ans=-1;
        for(int i=0;i<n;i++){
            if(sum>nums[i]){
                ans=max(ans,sum+nums[i]);
            }
            sum+=nums[i];
        }
        return ans;
    }
};