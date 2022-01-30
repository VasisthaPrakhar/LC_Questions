class Solution {
public:
    bool wordBreak(string s, vector<string>& wd) {
        int n=s.length();
        vector<bool>dp(n+1);
        dp[0]=true;
        for(int i=1;i<=n;i++){
            for(auto x:wd){
                int l=x.length();
                if(i>=l && dp[i-l]){
                    if(s.substr(i-l,l).compare(x)==0){
                        dp[i]=true;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};