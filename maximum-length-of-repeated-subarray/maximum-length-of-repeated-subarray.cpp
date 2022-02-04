class Solution {
public:
    int findLength(vector<int>& text1, vector<int>& text2) {
        int n=text1.size();
        int m=text2.size();
        int ans=INT_MIN;
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(text1[i]==text2[j]){
                    dp[i+1][j+1]=1+dp[i][j];
                }
                ans=max(ans,dp[i+1][j+1]);
            }
        }
        return ans;
    }
};