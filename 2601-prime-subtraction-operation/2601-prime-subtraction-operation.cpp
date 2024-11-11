class Solution {
public:
    typedef long long int ll;
    set<ll> fun(ll n){
       vector<bool> prime(n + 1, true);
       prime[0] = false;
       prime[1] = false;
       ll m = sqrt(n);

       for (ll p = 2; p <= m; p++) {
           if (prime[p]) {
               for (ll i = p * 2; i <= n; i += p)
                   prime[i] = false;
           }
       }
       set<ll> ans;
       for (ll i = 0; i <= n; i++)
           if (prime[i])
               ans.insert(i);
           return ans;
    }

    bool primeSubOperation(vector<int>& nums) {
        int n=nums.size();
        set<ll>s=fun(*max_element(nums.begin(),nums.end()) + 100);
        for(int i=n-2;i>=0;i--){
            if(nums[i+1]==1){
                return false;
            }
            if(nums[i]>=nums[i+1]){
                auto it=s.upper_bound(nums[i]-nums[i+1]);
                if(nums[i]-(*it)<=0){
                    return false;
                }
                nums[i]=nums[i]-(*it);
            }
        }
        return true;
    }
};