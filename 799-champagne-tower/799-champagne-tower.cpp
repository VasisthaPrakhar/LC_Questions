class Solution {
public:
    double champagneTower(int p, int qr, int qg) {
        vector<vector<double>>dp(qr+2,vector<double>(qr+2,0.0));
        dp[0][0]=p;
        for(int i=0;i<=qr;i++){
            for(int j=0;j<=i;j++){
                if(dp[i][j]>=1.0){
                    dp[i+1][j]+=(dp[i][j]-1)/2;
                    dp[i+1][j+1]+=(dp[i][j]-1)/2;
                    dp[i][j]=1;
                }
            }
        }
        return dp[qr][qg];
    }
};