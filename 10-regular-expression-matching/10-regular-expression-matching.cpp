class Solution {
public:
    bool isMatch(string s, string p) {
      int n=s.length();
      int m=p.length();
      bool dp[n+1][m+1];
      memset(dp,false,sizeof(dp));
      dp[0][0]=true;
      for(int j=2;j<=m;j++){
        if(p[j-1]=='*'){
          dp[0][j]=dp[0][j-2];
        }else{
          dp[0][j]=false;
        }
      }
      for(int i=1;i<=n;i++){
          for(int j=1;j<=m;j++){
              if(s[i-1]==p[j-1] || p[j-1]=='.'){
                dp[i][j]=dp[i-1][j-1];
              }else if(j>1 && p[j-1]=='*'){
                 if(s[i-1]==p[j-2] || p[j-2]=='.'){
                   dp[i][j]=dp[i-1][j]||dp[i][j-2];
                 }else{
                     dp[i][j]=dp[i][j-2];
                 }
              }
          }
      }
       return dp[n][m]; 
    }
};