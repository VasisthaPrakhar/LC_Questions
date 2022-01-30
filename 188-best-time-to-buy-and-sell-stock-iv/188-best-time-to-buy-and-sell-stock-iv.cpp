class Solution {
public:
    int fun(vector<int>& p,int k,int h,int i, int &n,vector<vector<vector<int>>>&memo){
        if(k==0 || i==n){
            return 0;
        }
        if(!memo[i][k][h]){
            if(h){
                memo[i][k][h]=max(p[i]+fun(p,k-1,0,i+1,n,memo),fun(p,k,h,i+1,n,memo));
            }else{
                memo[i][k][h]=max(-p[i]+fun(p,k,1,i+1,n,memo),fun(p,k,h,i+1,n,memo));
            }
        }
        return memo[i][k][h];
    }
    int maxProfit(int k, vector<int>& p) {
        int n=p.size();
        if(k==0 || n==0){
            return 0;
        }
       vector<vector<vector<int>>>memo(n,vector<vector<int>>(k+1,vector<int>(2,0)));
        return fun(p,k,0,0,n,memo);
    }
};