class Solution {
public:
    int dp[52][52];
    int fun(int i,int j,vector<int>& a,int n){
        if(i>j-2){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int res=INT_MAX;
        for(int k=i+1;k<j;k++){
            res=min(res, a[i]*a[k]*a[j]+fun(i,k,a,n)+fun(k,j,a,n));
        }
        return dp[i][j]=res;
    }
    int minScoreTriangulation(vector<int>& val) {
        int n=val.size();
        memset(dp,-1,sizeof(dp));
        return fun(0,n-1,val,n);
    }
};