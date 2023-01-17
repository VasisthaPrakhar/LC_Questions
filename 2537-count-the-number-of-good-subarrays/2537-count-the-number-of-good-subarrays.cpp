class Solution {
public:
    typedef long long int ll;
    ll su(ll n){
        return (n*(n+1))/2;
    }
    bool check(unordered_map<int,int>&m, int k){
        ll s=0;
        for(auto x:m){
            s+=su(x.second-1);
        }
        return s>=k;
    }
    long long countGood(vector<int>& nums, int k) {
        ll ans=0;
        int n=nums.size(),i=0,j=0;
        unordered_map<int,int>m;
        ll s=0;
        while(j<n){
            s+=m[nums[j]]++;
            while(i<j && s>=k){
                s-=--m[nums[i]];
                if(m[nums[i]]==0){
                    m.erase(nums[i]);
                }
                i++;
                ans+=n-j;
            }
            j++;
        }
        return ans;
    }
};