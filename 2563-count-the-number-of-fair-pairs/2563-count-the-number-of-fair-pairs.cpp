class Solution {
public:
    typedef long long int ll;
    ll fun(vector<int>& nums,int k){
        int n=nums.size();
        ll i=0,j=n-1,ans=0;
        while(i<j){
            while(i<j && nums[i]+nums[j]>k){j--;}
            ans+=j-i;
            i++;
        }
        return ans;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        return fun(nums,upper)-fun(nums,lower-1);
    }
};