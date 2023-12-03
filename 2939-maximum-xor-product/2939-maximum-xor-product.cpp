class Solution {
public:
    typedef long long int ll;
    int mod=1e9 + 7;
    int maximumXorProduct(long long a, long long b, int n) {
        ll x=0;
        for(ll i=n-1;i>=0;i--){
            ll k=1LL<<i;
            //cout<<k<<endl;
            if((a&k) == (b&k)){
                if((a&k)==0)
                    x|=k;
            }else{
                if((a^x) < (b^x)){
                    if((a&k)==0){
                        x|=k;
                    }
                }else{
                    if((b&k)==0){
                        x|=k;
                    }
                }
            }
        }
        //cout<<x<<endl;
        return (((a^x)%mod)*((b^x)%mod))%mod;
    }
};