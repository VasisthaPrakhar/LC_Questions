class Solution {
public:
    typedef long long int ll;
    long long minEnd(int n, int x) {
        vector<int>a;
        ll ans=x;
        for(ll i=0;i<63;i++){
            ll temp=1LL<<i;
            if(!((ll)x & temp)){
                a.push_back(i);
            }
        }
        for(int i=0;i<32;i++){
            ll temp=1<<i;
            if((n-1) & temp){
                ll k=1LL<<(ll)a[i];
                ans|=k;
            }
        }
        return ans;
    }
};