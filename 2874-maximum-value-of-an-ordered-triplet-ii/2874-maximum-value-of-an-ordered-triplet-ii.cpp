class Solution {
public:
    typedef long long int ll;
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        vector<ll>suf(n,0),pre(n,0);
        ll ma=-1;
        for(int i=n-1;i>=0;i--){
            suf[i]=ma;
            ma=max(ma,(ll)nums[i]);
        }
        ma=-1;
        for(int i=0;i<n;i++){
            pre[i]=ma;
            ma=max(ma,(ll)nums[i]);
        }
        ll ans=0;
        for(int i=1;i<n-1;i++){
            ans=max(ans,(pre[i]-nums[i])*suf[i]);
        }
        return ans;
    }
};