class Solution {
public:
    int findLength(vector<int>& text1, vector<int>& text2) {
        int n=text1.size();
        int m=text2.size();
        int ans=INT_MIN;
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};