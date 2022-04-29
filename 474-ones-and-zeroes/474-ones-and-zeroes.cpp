class Solution {
public:
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
    // int dp(int n1,vector<string>&strs,int m,int n){
    //     if(n1==0 ||(m<=0 && n<=0)){
    //         return 0;
    //     }
    //     if(memo[n1][m][n]==0){
    //         auto p=fun(strs[n1-1]);
    //         if(p.first<=m && p.second<=n){
    //             memo[n1][m][n]= max(1+dp(n1-1,strs,m-p.first,n-p.second),dp(n1-1,strs,m,n)); 
    //         }else{
    //             memo[n1][m][n]=dp(n1-1,strs,m,n);
    //         }
    //     }
    //     return memo[n1][m][n];
    // }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int k=strs.size();
        int memo[k+1][m+1][n+1];
        memset(memo,0,sizeof(memo));
        //dp(k,strs,m,n);
        for(int i=1;i<=k;i++){
            for(int j=0;j<=m;j++){
                for(int p=0;p<=n;p++){
                    auto p1=fun(strs[i-1]);
                    if(p1.first<=j && p1.second<=p){
                        memo[i][j][p]=max(memo[i-1][j][p],1+memo[i-1][j-p1.first][p-p1.second]);
                    }else{
                        memo[i][j][p]=memo[i-1][j][p];
                    }
                }
            }
        }
        return memo[k][m][n];
    }
};