class Solution {
public:
    int dp[2][101][201];
    int fun(int idx,int m,int n,vector<int>&p,int z){
        if(idx>=n){
            return 0;
        }
        if(dp[z][idx][m]!=-1){
            return dp[z][idx][m];
        }
        int s=0,j=0;
        int res=(z==0)?0:INT_MAX;
        for(int i=0;i<2*m;i++){
            if(idx+i<n){
                s+=p[idx+i];
                j++;
                int k=max(m,j);
                if(z){
                    res=min(res,fun(idx+i+1,k,n,p,(z+1)%2));
                }else{
                    res=max(res,s+fun(idx+i+1,k,n,p,(z+1)%2));   
                }
            }
        }
        return dp[z][idx][m]=res;
    }
    int stoneGameII(vector<int>& p) {
        int n=p.size();
        memset(dp,-1,sizeof(dp));
        return fun(0,1,n,p,0);
    }
};