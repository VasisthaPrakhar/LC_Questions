class Solution {
public:
    int dp[100001];
    vector<int>a;
    typedef long long int ll;
    int fun(vector<vector<int>>&v,int n, int idx,int last){
        if(idx>=n){
            return 0;
        }
        // if(v[idx][0]<=last){
        //     return fun(v,n,idx+1,last);
        // }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        ll res=0;
        int z=upper_bound(a.begin()+idx+1,a.end(),v[idx][1])-a.begin();
        res=max(v[idx][2]+fun(v,n,z,v[idx][1]),fun(v,n,idx+1,last));
        return dp[idx]=res;
    }
    int maximizeTheProfit(int n, vector<vector<int>>& v) {
        int m=v.size();
        if(m==1){
            return v[0][2];
        }
        sort(v.begin(),v.end());
        for(int i=0;i<m;i++){
            a.push_back(v[i][0]);
        }
        //vector<ll>dp(m+1,-1);
        memset(dp,-1,sizeof(dp));
        return fun(v,m,0,-1);
    }
};