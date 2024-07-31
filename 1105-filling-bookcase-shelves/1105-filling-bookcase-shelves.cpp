class Solution {
public:
    int dp[1001][1001];
    int fun(int idx,vector<vector<int>>& b,int w,int h,int n,int s){
        if(idx>=n){
            return h;
        }
        if(dp[idx][w]!=-1){return dp[idx][w];}
        int res1=h+fun(idx+1,b,s-b[idx][0],b[idx][1],n,s),res2=INT_MAX;
        if(b[idx][0]<=w){
            res2=fun(idx+1,b,w-b[idx][0],max(h,b[idx][1]),n,s);
        }
        return dp[idx][w]=min(res1,res2);
    }
    int minHeightShelves(vector<vector<int>>& b, int w) {
        int n=b.size();
        memset(dp,-1,sizeof(dp));
        return fun(0,b,w,0,n,w);
    }
};