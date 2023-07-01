class Solution {
public:
    typedef long long int ll;
    int maxProduct(vector<int>& a) {
        int n=a.size();
        ll mi=1,ma=1,ans=INT_MIN;
        for(int i=0;i<n;i++){
            ll t=max((ll)a[i],ma*a[i]);
            ll t1=min((ll)a[i],ma*a[i]);
            ma=max(t,mi*a[i]);
            mi=min(t1,mi*a[i]);
            ans=max(ans,ma);
        }
        return ans;
    }
};