class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size(),ans=0;
        int dp[n][m];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            dp[i][0]=mat[i][0];
            ans+=mat[i][0];
        }
        for(int j=1;j<m;j++){
            dp[0][j]=mat[0][j];
            ans+=mat[0][j];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(mat[i][j]==1){
                    dp[i][j]+=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                }
                ans+=dp[i][j];
            }
        }
        return ans;
    }
};