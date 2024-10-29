class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size(),ans=0;
        int dp[n][m];
        memset(dp,0,sizeof(dp));
        for(int j=m-2;j>=0;j--){
            int res=0;
            for(int i=0;i<n;i++){
                if(i>0 && grid[i][j]<grid[i-1][j+1]){
                    dp[i][j]=max(dp[i][j],1+dp[i-1][j+1]);
                }
                if(i<n-1 && grid[i][j]<grid[i+1][j+1]){
                    dp[i][j]=max(dp[i][j],1+dp[i+1][j+1]);
                }
                if(grid[i][j]<grid[i][j+1]){
                    dp[i][j]= max(dp[i][j],1+dp[i][j+1]);
                }
                res=max(dp[i][j],res);
            }
            ans=res;
        }
        return ans;
    }
};