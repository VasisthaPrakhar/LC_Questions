class Solution {
public:
    int dp[1001][2001];
    int fun(vector<vector<int>>& p, int k,int n,int idx){
        if(idx==n || k==0){
            return 0;
        }
        if(dp[idx][k]!=-1){
            return dp[idx][k];
        }
        int res=fun(p,k,n,idx+1),cur=0;
        for(int i=0;i<p[idx].size() && i<k;i++){
            cur+=p[idx][i];
            res=max(res,cur+fun(p,k-(i+1),n,idx+1));
        }
        return dp[idx][k]=res;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n=piles.size();
        memset(dp,-1,sizeof(dp));
        return fun(piles,k,n,0);
    }
};