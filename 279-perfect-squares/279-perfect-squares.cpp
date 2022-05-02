class Solution {
public:
    int numSquares(int n) {
        vector<int>sq;
        int k=1;
        while(k*k<=n){
            sq.push_back(k*k);
            k++;
        }
        int m=sq.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<=n;i++){
            dp[0][i]=INT_MAX-1;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(j>=sq[i-1]){
                    dp[i][j]=min(dp[i-1][j],1+dp[i][j-sq[i-1]]);
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[m][n];
    }
};