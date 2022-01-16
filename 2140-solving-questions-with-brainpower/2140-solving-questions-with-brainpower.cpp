class Solution {
public:
    long long mostPoints(vector<vector<int>>& qu) {
        int n=qu.size();
        vector<long long>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            dp[i]=max(dp[i+1],qu[i][0]+dp[min(n,i+qu[i][1]+1)]);
        }
        return dp[0];
    }
};