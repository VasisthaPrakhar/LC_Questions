class Solution {
public:
    typedef long long int ll;
    long long countInterestingSubarrays(vector<int>& nums, int mod, int k) {
        int n=nums.size();
        vector<int>v(n+1,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]%mod == k){
                cnt++;
            }
            v[i+1]=cnt;
        }
        ll ans=0;
        // for(int i=1;i<=n;i++){
        //     int j=0;
        //     while(j<i){
        //         if((v[i]-v[j])%mod == k){
        //             ans++;
        //         }
        //         j++;
        //     }
        // }
        map<int,int>m;
        for(int i=0;i<=n;i++){
            ans+=m[(v[i] + mod - k) % mod];
            m[v[i] % mod]++;
        }
        // for(auto x:m){
        //     ans+=x.second;
        // }
        return ans;
    }
};