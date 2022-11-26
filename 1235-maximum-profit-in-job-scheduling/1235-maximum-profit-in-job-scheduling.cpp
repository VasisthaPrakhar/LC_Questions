typedef int ll;
class Solution {
public:
    vector<ll>dp;
    ll fun(vector<vector<ll>>&v,int idx,int last,int n){
        if(idx>=n){
            return 0;
        }
        if(v[idx][0]<last){
            return fun(v,idx+1,last,n);
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        ll res=0;
        res=max(v[idx][2]+fun(v,idx+1,v[idx][1],n),fun(v,idx+1,last,n));
        return dp[idx]=res;
    }
    int jobScheduling(vector<int>& st, vector<int>& end, vector<int>& p) {
        int n=st.size();
        if(n==1){
            return p[0];
        }
        vector<vector<ll>>v(n,vector<ll>(3));
        for(int i=0;i<n;i++){
            v[i][0]=st[i];
            v[i][1]=end[i];
            v[i][2]=p[i];
        }
        dp.resize(n+1,-1);
        sort(v.begin(),v.end());
        return fun(v,0,0,n);
    }
};