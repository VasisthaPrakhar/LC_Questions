class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        int sum=0;
        for(auto x:s1){
            sum+=x;
        }
        for(auto x:s2){
            sum+=x;
        }
        int dp[n+1][m+1];
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<=m;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=s1[i-1]+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return sum-2*dp[n][m];
    }
};