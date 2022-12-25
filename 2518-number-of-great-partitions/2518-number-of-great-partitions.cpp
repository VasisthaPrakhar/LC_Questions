class Solution {
public:
    typedef long long int ll;
    int mod=1e9 +7;
    map<int,unordered_map<ll,ll>>dp;
    int fun(vector<int>&nums,int k,int n, int idx, ll sum, ll tot){
        if(sum>k){
            return 0;
        }
        if(idx==n){
            if(sum<k){
                return 1;
            }
            return 0;
        }
        if(dp.find(idx)!=dp.end()){
            if(dp[idx].count(sum))
                return dp[idx][sum];
        }
        ll res=(fun(nums,k,n,idx+1,sum+nums[idx],tot)%mod + fun(nums,k,n,idx+1,sum,tot)%mod)%mod;
        return dp[idx][sum]=res;
    }
    int countPartitions(vector<int>& nums, int k) {
        int n=nums.size();
        ll tot=0;
        for(int i=0;i<n;i++){
            tot+=nums[i];
        }
        if(tot<2*k){
            return 0;
        }
        ll sum=0;
        ll ans=fun(nums,k,n,0,sum,tot)%mod;
        ans-=1;
        ll z=2;
        for(int i=1;i<n;i++){
            z*=2;
            z=z%mod;
        }
        z-=2;
        return (z-(2*ans)%mod+mod)%mod;
    }
};