class Solution {
public:
    typedef long long int ll;
    ll dp[50001];
    int fun(vector<vector<int>>&v,int n, int idx,int last,vector<int>&st){
        if(idx>=n){
            return 0;
        }
        if(v[idx][0]<last){
            auto f=lower_bound(st.begin()+idx+1,st.end(),last)-st.begin();
            return fun(v,n,f,last,st);
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        ll res=0;
        res=max(v[idx][2]+fun(v,n,idx+1,v[idx][1],st),fun(v,n,idx+1,last,st));
        return dp[idx]=res;
    }
    int jobScheduling(vector<int>& st, vector<int>& end, vector<int>& p) {
        int n=st.size();
        if(n==1){
            return p[0];
        }
        vector<vector<int>>v(n,vector<int>(3));
        for(int i=0;i<n;i++){
            v[i][0]=st[i];
            v[i][1]=end[i];
            v[i][2]=p[i];
        }
        sort(v.begin(),v.end());
        sort(st.begin(),st.end());
        memset(dp,-1,sizeof(dp));
        return fun(v,n,0,0,st);
    }
};