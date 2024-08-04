class Solution {
public:
    typedef long long int ll;
    int mod=1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<ll>a;
        for(int i=0;i<n;i++){
            ll s=0;
            for(int j=i;j<n;j++){
                s+=nums[j];
                a.push_back(s);
            }
        }
        sort(a.begin(),a.end());
        ll ans=0;
        for(int i=left-1;i<right;i++){
            ans+=a[i];
        }
        return ans%mod;
    }
};