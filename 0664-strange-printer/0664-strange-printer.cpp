class Solution {
public:
    int dp[101][101];
    int fun(string &t, int i, int j){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(j-i==0){
            return 1;
        }
        if(j-i==1){
            return t[j]==t[i]?1:2;
        }
        int res=1+fun(t,i+1,j);
        for(int k=i+1;k<=j;k++){
            if(t[k]==t[i])
                res=min(res,fun(t,i+1,k-1)+fun(t,k,j));
        }
        return dp[i][j]=res;
    }
    int strangePrinter(string s) {
        int n=s.length();
        int j=0;
        string t="";
        while(j<n){
            while(j<n-1 && s[j]==s[j+1]){
                j++;
            }
            t.push_back(s[j]);
            j++;
        }
        memset(dp,-1,sizeof(dp));
        return fun(t,0,(int)t.length()-1);
    }
};