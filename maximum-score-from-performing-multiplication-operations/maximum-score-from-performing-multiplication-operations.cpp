class Solution {
public:
    int maximumScore(vector<int>& num, vector<int>& mul) {
        int n=num.size();
        int m=mul.size();
        vector<vector<int>>dp(m+1,vector<int>(m+1,0));
        for(int i=m-1;i>=0;i--){
            int k=mul[i];
            for(int left=i;left>=0;left--){
                int right=n-1-(i-left);
                dp[i][left]=max(num[right]*k+dp[i+1][left],num[left]*k+dp[i+1][left+1]);
            }
        }
        return dp[0][0];
    }
};