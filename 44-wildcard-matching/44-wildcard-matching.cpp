class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        if(n==0 && m==0){
            return true;
        }
        if(m==0){
            return false;
        }
        bool dp[n+1][m+1];
        memset(dp,false,sizeof(dp));
        dp[0][0]=true;
        for(int i=0;i<m && p[i]=='*';i++){
            dp[0][i+1]=true;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?'){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    if(p[j-1]=='*')
                        dp[i][j]=dp[i-1][j]||dp[i][j-1];
                }
            }
        }
        return dp[n][m];
    }
};