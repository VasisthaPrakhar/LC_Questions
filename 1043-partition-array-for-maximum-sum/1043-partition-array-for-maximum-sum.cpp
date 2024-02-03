class Solution {
public:
    typedef long long int ll;
    int dp[501];
    ll fun(vector<int> &a, int idx, int n,int k){
        if(idx<0 || idx>=n){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int l=k;
        ll res=0;
        while(l>0){
            ll z=0,c=0;
            for(int i=idx-l+1;i<=idx;i++){
                if(i>=0){
                    z=max(z,(ll)a[i]);
                    c++;
                }
            }
            //cout<<l<<" "<<z<<" "<<idx<<endl;
            res=max(res, fun(a,idx-l,n,k) + z*c);
            l--;
        }
        return dp[idx]=res;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        memset(dp,-1,sizeof(dp));
        return fun(arr,n-1,n,k);
    }
};