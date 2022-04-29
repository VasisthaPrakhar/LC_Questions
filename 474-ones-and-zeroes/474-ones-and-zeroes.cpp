class Solution {
public:
    int memo[601][101][101];
    pair<int,int> fun(string &s){
        int c0=0,c1=0;
        for(auto x:s){
            if(x=='0'){
                c0++;
            }else{
                c1++;
            }
        }
        return {c0,c1};
    }
    int dp(int n1,vector<string>&strs,int m,int n){
        if(n1==0 ||(m<=0 && n<=0)){
            return 0;
        }
        if(memo[n1][m][n]==0){
            auto p=fun(strs[n1-1]);
            if(p.first<=m && p.second<=n){
                memo[n1][m][n]= max(1+dp(n1-1,strs,m-p.first,n-p.second),dp(n1-1,strs,m,n)); 
            }else{
                memo[n1][m][n]=dp(n1-1,strs,m,n);
            }
        }
        return memo[n1][m][n];
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int k=strs.size();
        memset(memo,0,sizeof(memo));
        dp(k,strs,m,n);
        return memo[k][m][n];
    }
};