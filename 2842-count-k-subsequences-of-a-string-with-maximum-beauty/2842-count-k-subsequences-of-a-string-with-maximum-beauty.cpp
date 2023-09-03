class Solution {
public:
    typedef long long int ll;
    int mod = 1e9+7;
    ll power(ll a, ll b){
        ll ans=1;
        while(b){
            ans= (ans%mod * a%mod)%mod;
            b--;
        }
        return ans;
    }
    ll fun (int n, int r){
        double sum = 1;
        for(int i = 1; i <= r; i++){
            sum = sum * (n - r + i) / i;
        }
        return (ll)sum;
    }
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        int n=s.length();
        unordered_map<char,int>m;
        for(auto x:s){
            m[x]++;
        }
        vector<int>a;
        for(auto x:m){
            a.push_back(x.second);
        }
        m.clear();
        for(auto x:a){
            m[x]++;
        }
        if(a.size()<k){
            return 0;
        }
        sort(a.begin(),a.end());
        int j=a.size()-1,z=k;
        ll sum=0;
        map<int,int>temp;
        while(z){
            sum+=a[j];
            temp[a[j]]++;
            j--,z--;
        }
        auto it=temp.begin();
        int r=it->second;
        int no = m[it->first];
        ll x = fun(no,r);
        vector<ll>res;
        res.push_back(x);
        while(it !=temp.end()){
            ll v = (ll)power(it->first,it->second)%mod;
            res.push_back(v);
            it++;
        }
        ll ans=1;
        for(auto x:res){
            ans = (ans%mod * x%mod)%mod;
        }
        return ans;
    }
};