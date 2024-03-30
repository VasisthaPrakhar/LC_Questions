class Solution {
public:
    typedef long long int ll;
    ll fun(vector<int>&nums, int &n, int k){
        ll i=0,j=0,ans=0;
        unordered_map<int,int>m;
        while(j<n){
            m[nums[j]]++;
            while(i<=j && m.size()>k){
                m[nums[i]]--;
                if(m[nums[i]]==0){
                    m.erase(nums[i]);
                }
                i++;
            }
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        ll ans=fun(nums,n,k);
        ll ans1=fun(nums,n,k-1);
        return ans-ans1;
    }
};