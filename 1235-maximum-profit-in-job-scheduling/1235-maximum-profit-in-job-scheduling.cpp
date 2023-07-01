class Solution {
public:
    typedef long long int ll;
    int fun(vector<vector<int>>&v,int n, int idx,int last, vector<ll>&dp){
        if(idx>=n){
            return 0;
        }
        if(v[idx][0]<last){
            return fun(v,n,idx+1,last,dp);
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        ll res=0;
        //else{
            res=max(v[idx][2]+fun(v,n,idx+1,v[idx][1],dp),fun(v,n,idx+1,last,dp));
        //}
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
        vector<ll>dp(n,-1);
        return fun(v,n,0,0,dp);
    }
};