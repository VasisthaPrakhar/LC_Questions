class Solution {
public:
    typedef long long int ll;
    bool fun(ll x){
        if(x<0) return false;
        return x && (!(x & (x - 1)));
    }
    long long wonderfulSubstrings(string &w) {
        int n=w.length();
        unordered_map<ll,int>m;
        m[0]++;
        ll a=0,ans=0;
        for(int i=0;i<n;i++){
            a=a^(1<<(w[i]-'a'));
            for(auto &x:m){
                if(fun(x.first ^ a) || x.first==a){
                    //cout<<i<<" "<<x.first<<" "<<a<<endl;
                    ans+=x.second;
                }
            }
            //cout<<ans<<endl;
            m[a]++;
        }
        return ans;
    }
};