class Solution {
public:
    typedef long long int ll;
    int mod=1e9+7;
    ll fun(vector<int>&a, int n){
        ll res=INT_MIN,curr=0;
        for(int i=0;i<n;i++){
            curr=max(curr+a[i],(ll)a[i]);
            res=max(curr,res);
        }
        return res;
    }
    ll fun1(vector<int>&a, int n){
        ll res=INT_MAX,curr=0;
        for(int i=0;i<n;i++){
            curr=min(curr+a[i],(ll)a[i]);
            res=min(curr,res);
        }
        return res;
    }
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int n=arr.size();
        ll sum=accumulate(arr.begin(),arr.end(),0LL);
        ll ma=fun(arr,n);
        ll bond=sum-fun1(arr,n);
        ll ans=0;
        if(k==1){
            return ma>0?ma:0;
        }
        int f=0;
        ans=max({ans,bond,ma});
        if(ans==bond){
            f=1;
        }
        ll res = max({ans,(k-1)*sum + ma,ma})%mod;
        if(f){
            res = max({ans,(k-1)*sum + ma,ma})%mod;
        }
        return res%mod;
    }
};