class Solution {
public:
    typedef long long int ll;
    // vector<vector<ll>>dp;
    // ll fun(int i,int j,vector<int>&a,vector<int>&b){
    //     if(i<0){
    //         return 0;
    //     }
    //     if(j<0){
    //         return (ll)1e12;
    //     }
    //     if(dp[i][j]!=-1){
    //         return dp[i][j];
    //     }
    //     ll res=LLONG_MAX;
    //     res=min(res,abs(a[i]-b[j])+fun(i-1,j-1,a,b));
    //     res=min(res,fun(i,j-1,a,b));
    //     return dp[i][j]=res;
    // }
    long long minimumTotalDistance(vector<int>& r, vector<vector<int>>& f) {
        sort(r.begin(),r.end());
        sort(f.begin(),f.end());
        vector<int>pos;
        for(auto x:f){
            int k=x[1];
            while(k--){
                pos.push_back(x[0]);
            }
        }
        int n=r.size(),m=pos.size();
        // dp.resize(n,vector<ll>(m,-1));
        // return fun(n-1,m-1,r,pos);
        ll dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            dp[i][0]=1e12;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j]=min(abs(r[i-1]-pos[j-1])+dp[i-1][j-1],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};