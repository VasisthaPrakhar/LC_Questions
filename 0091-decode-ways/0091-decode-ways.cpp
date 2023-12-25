class Solution {
public:
    int fun(int idx,int n,string &s,vector<int>&dp){
        if(idx>=n){
            return idx==n?1:0;
        }
        if(s[idx]=='0'){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int res=0;
        if(s[idx]=='1'){
            res=fun(idx+1,n,s,dp)+fun(idx+2,n,s,dp);
        }else if(s[idx]=='2'){
            res+=fun(idx+1,n,s,dp);
            if(idx<n-1 && s[idx+1]<='6'){
                res+=fun(idx+2,n,s,dp);
            }
        }else{
            res=fun(idx+1,n,s,dp);
        }
        return dp[idx]=res;
    }
    int numDecodings(string s) {
        int n=s.length();
        vector<int>dp(n+1,-1);
        return fun(0,n,s,dp);
    }
};