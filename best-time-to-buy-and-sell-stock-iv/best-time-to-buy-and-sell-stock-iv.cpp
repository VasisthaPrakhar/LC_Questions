class Solution {
public:
    // int fun(vector<int>& p,int k,int h,int i, int &n,vector<vector<vector<int>>>&memo){
    //     if(k==0 || i==n){
    //         return 0;
    //     }
    //     if(!memo[i][k][h]){
    //         if(h){
    //             memo[i][k][h]=max(p[i]+fun(p,k-1,0,i+1,n,memo),fun(p,k,h,i+1,n,memo));
    //         }else{
    //             memo[i][k][h]=max(-p[i]+fun(p,k,1,i+1,n,memo),fun(p,k,h,i+1,n,memo));
    //         }
    //     }
    //     return memo[i][k][h];
    // }
    int maxProfit(int k, vector<int>& p) {
        int n=p.size();
        if(k==0 || n==0){
            return 0;
        }
       vector<vector<vector<int>>>memo(n+1,vector<vector<int>>(k+1,vector<int>(2,0)));
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=k;j++){
                for(int m=0;m<2;m++){
                    if(m){
                        memo[i][j][m]=max(p[i]+memo[i+1][j-1][0],memo[i+1][j][m]);
                    }else{
                        memo[i][j][m]=max(-p[i]+memo[i+1][j][1],memo[i+1][j][m]);
                    }
                }
            }
        }
        return memo[0][k][0];
    }
};