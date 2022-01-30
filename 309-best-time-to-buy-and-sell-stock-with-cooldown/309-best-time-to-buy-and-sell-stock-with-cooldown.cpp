class Solution {
public:
    int fun(vector<int>& p,int h,int i, int &n,vector<vector<int>>&memo){
        if(i>=n){
            return 0;
        }
        if(!memo[i][h]){
            if(h){
                memo[i][h]=max(p[i]+fun(p,0,i+2,n,memo),fun(p,h,i+1,n,memo));
            }else{
                memo[i][h]=max(-p[i]+fun(p,1,i+1,n,memo),fun(p,h,i+1,n,memo));
            }
        }
        return memo[i][h];
    }

    int maxProfit(vector<int>& p) {
        int n=p.size();
        if(n==0){
            return 0;
        }
       vector<vector<int>>memo(n,vector<int>(2,0));
        return fun(p,0,0,n,memo);
    }
};