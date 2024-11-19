class Solution {
public:
    typedef long long int ll;
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int j=0,i=0;
        ll sum=0,ans=0;
        unordered_map<int,int>m;
        for(j=0;j<k;j++){
            sum+=nums[j];
            m[nums[j]]++;
        }
        if(m.size()==k){
            ans=sum;
        }
        while(j<n){
            sum+=nums[j];
            m[nums[j]]++;
            sum-=nums[i];
            m[nums[i]]--;
            if(m[nums[i]]==0){
                m.erase(nums[i]);
            }
            if(m.size()==k){
                ans=max(ans,sum);
            }
            i++,j++;
        }
        return ans;
    }
};