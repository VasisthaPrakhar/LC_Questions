typedef long long int ll;
class Solution {
public:
    long long int dp(vector<int>& h, vector<vector<int>>& c, int &m, int &n, int t, int idx, vector<vector<vector<int>>>&memo,int last){
        if(idx>=m || t<0){
            return t==0?0:INT_MAX;
        }
        if(h[idx]!=0){
            return dp(h,c,m,n,t-(last!=h[idx]),idx+1,memo,h[idx]);
        }
        if(!memo[idx][t][last]){
            int res=INT_MAX;
            for(int i=0;i<n;i++){
                res=min((ll)res,(ll)c[idx][i]+dp(h,c,m,n,t-(last!=(i+1)),idx+1,memo,i+1));
            }
            memo[idx][t][last]=res;
        }
        return memo[idx][t][last];
    }
    int minCost(vector<int>& h, vector<vector<int>>& c, int m, int n, int t) {
        vector<vector<vector<int>>>memo(m,vector<vector<int>>(t+1,vector<int>(n+1,0)));
        int ans=dp(h,c,m,n,t,0,memo,0);
        return ans==INT_MAX?-1:ans;
    }
};