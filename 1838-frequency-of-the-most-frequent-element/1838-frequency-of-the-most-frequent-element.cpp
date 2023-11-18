class Solution {
public:
    typedef long long int ll;
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        ll n=nums.size(),ans=0;
        ll sum=0,j=0,i=0;
        while(j<n){
            sum+=nums[j];
            while(i<j && (((j-i+1)*(ll)nums[j])-sum)>k){
                sum-=nums[i];
                i++;
            }
            ans=max(j-i+1,ans);
            j++;
        }
        return ans;
    }
};