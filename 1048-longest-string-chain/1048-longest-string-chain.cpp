class Solution {
public:
    bool check(string &a,string &b){
        int n=a.length();
        int m=b.length();
        if(n-m!=1){
            return false;
        }
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i-1]==b[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m]==m;
    }
    int longestStrChain(vector<string>& w) {
        sort(w.begin(),w.end(),[](string &a,string &b)->bool{
            return a.length()<b.length();
        });
        int n=w.size(),ans=1;
        vector<int>dp(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(check(w[i],w[j])){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};