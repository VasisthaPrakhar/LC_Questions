class Solution {
public:
    typedef long long int ll;
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int ma=*max_element(nums.begin(),nums.end());
        ll j=0,i=0,ans=0;
        unordered_map<int,int>m;
        while(j<n){
            m[nums[j]]++;
            while(i<=j && m[ma]>=k){
                m[nums[i]]--;
                ans+=n-j;
                i++;
            }
            j++;
        }
        return ans;
    }
};