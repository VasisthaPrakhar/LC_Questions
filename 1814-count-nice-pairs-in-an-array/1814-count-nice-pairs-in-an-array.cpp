class Solution {
public:
    typedef long long int ll;
    ll mod=1e9 + 7;
    int rev(int n){
        int k=0;
        while(n){
            k=k*10+(n%10);
            n/=10;
        }
        return k;
    }
    int countNicePairs(vector<int>& nums) {
        int n=nums.size();
        map<ll,ll>m;
        for(auto x:nums){
            m[rev(x)-x]++;
        }
        ll ans=0;
        for(int i=0;i<n;i++){
            ans=ans + (ll)(m[rev(nums[i])-nums[i]]-1);
        }
        //cout<<ans<<endl;
        return (ans/2)%mod;
    }
};