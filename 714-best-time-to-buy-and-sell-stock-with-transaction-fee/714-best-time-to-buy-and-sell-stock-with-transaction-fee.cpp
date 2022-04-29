class Solution {
public:
    int fun(vector<int>& p,int h,int i, int &n,vector<vector<int>>&memo,int &fee){
        if(i==n){
            return 0;
        }
        if(memo[i][h]==0){
            if(h){
                memo[i][h]=max(-fee+p[i]+fun(p,0,i+1,n,memo,fee),fun(p,h,i+1,n,memo,fee));
            }else{
                memo[i][h]=max(-p[i]+fun(p,1,i+1,n,memo,fee),fun(p,h,i+1,n,memo,fee));
            }
        }
        return memo[i][h];
    }
    int maxProfit(vector<int>& p, int fee) {
        int n=p.size();
        if(n==0){
            return 0;
        }
       //vector<vector<int>>memo(n+1,vector<int>(2,0));
        int b=INT_MAX,s=0;
        for(int i=0;i<n;i++){
            b=min(b,p[i]-s);
            s=max(s,-b+p[i]-fee);
        }
        return s;   
    }
};