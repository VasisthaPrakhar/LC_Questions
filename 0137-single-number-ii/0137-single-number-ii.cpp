class Solution {
public:
    typedef long long int ll;
    vector<ll>fun(ll x){
        vector<ll>ans;
        while(x){
            ans.push_back(x%2);
            x/=2;
        }
        return ans;
    }
    int singleNumber(vector<int>& nums) {
        vector<ll>a(32,0),b(32,0);
        for(auto x:nums){
            if(x>=0){
                vector<ll>t=fun(x);
                for(ll i=0;i<t.size();i++){
                    a[i]+=t[i];
                }
            }else{
                vector<ll>t=fun(abs(x));
                for(ll i=0;i<t.size();i++){
                    b[i]+=t[i];
                }
            }
        }
        int ans=0,ans1=0;
        for(ll i=0;i<32;i++){
            if(a[i]%3!=0){
                ans+=1<<i;
            }
            if(b[i]%3!=0){
                ans1+=1<<i;
            }
        }
        if(ans1<0)return ans1;
        return ans>ans1?ans:-ans1;
    }
};