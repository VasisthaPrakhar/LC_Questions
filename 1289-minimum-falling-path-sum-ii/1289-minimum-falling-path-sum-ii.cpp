class Solution {
public:
    typedef long long int ll;
    int dp[204][204];
    ll fun(int r,int prev,int n,vector<vector<int>>& grid){
        if(r>=n){
            return 0;
        }
        if(dp[r][prev]!=-1){
            return dp[r][prev];
        }
        ll res=INT_MAX;
        for(int i=0;i<n;i++){
            if(i!=prev-1){
                res=min(res,grid[r][i]+fun(r+1,i+1,n,grid));
            }
        }
        return dp[r][prev]=res;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        memset(dp,-1,sizeof(dp));
        return fun(0,0,n,grid);
    }
};