class Solution {
public:
    int integerBreak(int am) {
        vector<int>co(am-1);
        int n=am-1;
        for(int i=1;i<=n;i++){
            co[i-1]=i;
        }
        int dp[n+1][am+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=am;i++){
            dp[0][i]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<=am;j++){
                if(j>=co[i-1]){
                    dp[i][j]=max(dp[i-1][j],co[i-1]*dp[i][j-co[i-1]]);
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][am];
    }
};