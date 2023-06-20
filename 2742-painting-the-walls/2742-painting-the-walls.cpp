class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n=cost.size();
        int dp[n+1][n+1];
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<=n;i++){
            dp[0][i]=1e9+7;
        }
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                //if(j>time[i-1])
                dp[i][j]=min(dp[i-1][j],dp[i-1][max(j-time[i-1]-1,0)]+cost[i-1]);
                // else{
                //     dp[i][j]=dp[i-1][j];
                // }
            }
        }
        // for(int i=0;i<=n;i++){
        //     for(int j=0;j<=n;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[n][n];
    }
};