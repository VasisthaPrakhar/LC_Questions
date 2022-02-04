class Solution {
public:
    int findLength(vector<int>& text1, vector<int>& text2) {
        int n=text1.size();
        int m=text2.size();
        int ans=INT_MIN;
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(text1[i]==text2[j]){
                    dp[i][j]=1+dp[i+1][j+1];
                }
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};