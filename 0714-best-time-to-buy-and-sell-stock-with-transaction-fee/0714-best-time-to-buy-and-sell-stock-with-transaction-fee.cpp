class Solution {
public:
    int fun(vector<int>& p,int h,int idx, int &n,vector<vector<int>>&memo,int &fee){
        if(idx==n){
            return 0;
        }
        if(memo[idx][h]==0){
            if(h){
                memo[idx][h]=max(-fee+p[idx]+fun(p,0,idx+1,n,memo,fee),fun(p,h,idx+1,n,memo,fee));
            }else{
                memo[idx][h]=max(-p[idx]+fun(p,1,idx+1,n,memo,fee),fun(p,h,idx+1,n,memo,fee));
            }
        }
        return memo[idx][h];
    }
    int maxProfit(vector<int>& p, int fee) {
        int n=p.size();
        if(n==0){
            return 0;
        }
       vector<vector<int>>memo(n+1,vector<int>(2,0));
        return fun(p,0,0,n,memo,fee);   
    }
};