class Solution {
public:
    int change(int am, vector<int>& co) {
        int n=co.size();
        vector<vector<int>>dp(n+1,vector<int>(am+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<=am;j++){
                if(j>=co[i-1]){
                    dp[i][j]=dp[i-1][j]+dp[i][j-co[i-1]];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][am];
    }
};