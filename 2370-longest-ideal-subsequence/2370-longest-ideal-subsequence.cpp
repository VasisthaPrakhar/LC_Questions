class Solution {
public:
    
    // int fun(string &s, int n, int idx, int prev,int k,unordered_map<int,unordered_map<int,int>>&dp){
    //     if(idx>=n){
    //         return 0;
    //     }
    //     if(dp.find(idx)!=dp.end()){
    //         if(dp[idx].find(prev)!=dp[idx].end())
    //             return dp[idx][prev];
    //     }
    //     int res=fun(s,n,idx+1,prev,k,dp);
    //     if(abs((s[idx]-'a')-prev)<=k || prev==-1){
    //         res=max(res,1+fun(s,n,idx+1,s[idx]-'a',k,dp));
    //     }
    //     return dp[idx][prev]=res;
    // }
    int longestIdealString(string s, int k) {
        int n=s.length(),ans=1;
        // unordered_map<int,unordered_map<int,int>>dp;
        // return fun(s,n,0,-1,k,dp);
        vector<int>dp(26,0);
        for(int i=0;i<n;i++){
            int num=s[i]-'a',ma=-1;
            for(int j=max(0,num-k);j<=min(25,num+k);j++){
                ma=max(ma,dp[j]);
            }
            dp[num]=ma+1;
            ans=max(ans,dp[num]);
        }
        return ans;
    }
};