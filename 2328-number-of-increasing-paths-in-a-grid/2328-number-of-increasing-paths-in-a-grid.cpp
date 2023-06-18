class Solution {
public:
    typedef long long int ll;
    int mod=1e9+7;
    unordered_map<int,unordered_map<int,int>>dp;
    int dr[4]={1,-1,0,0};
    int dc[4]={0,0,1,-1};
    ll fun(int r,int c,int n,int m,vector<vector<int>>& grid, int prev){
        if(r<0 || r>=n || c<0 || c>=m || grid[r][c]<=prev){
            return 0;
        }
        if(dp.count(r)){
            if(dp[r].count(c)){
                return dp[r][c];
            }
        }
        ll res=1;
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            res= (res%mod + fun(nr,nc,n,m,grid,grid[r][c])%mod)%mod;
        }
        return dp[r][c]=res;
    }
    int countPaths(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        ll ans=0;
        dp.clear();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=(ans%mod + fun(i,j,n,m,grid,0)%mod)%mod;
            }
        }
        return ans;
    }
};