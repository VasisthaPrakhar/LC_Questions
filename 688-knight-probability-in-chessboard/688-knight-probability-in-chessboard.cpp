class Solution {
public:
    int dr[8]={2,1,2,1,-1,-1,-2,-2};
    int dc[8]={1,2,-1,-2,2,-2,1,-1};
    double dp[101][26][26];
    double fun(int n,int k,int r,int c){
        if(r<0 || r>=n || c<0 || c>=n){
            return 0;
        }
        if(k==0){
            return 1;
        }
        if(dp[k][r][c]!=0){
            return dp[k][r][c];
        }
        double res=0;
        for(int i=0;i<8;i++){
            res+=0.125*fun(n,k-1,r+dr[i],c+dc[i]);
        }
        return dp[k][r][c]=res;
    }
    double knightProbability(int n, int k, int row, int column) {
        memset(dp,0,sizeof(dp));
        return fun(n,k,row,column);
    }
};