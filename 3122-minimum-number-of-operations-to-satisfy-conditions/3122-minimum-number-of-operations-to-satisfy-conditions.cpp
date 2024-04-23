class Solution {
public:
    unordered_map<int,unordered_map<int,int>>dp;
    int fun(int idx,int n,int num,unordered_map<int,unordered_map<int,int>>&a,int prev){
        if(idx>=n){
            return 0;
        }
        if(dp.find(idx)!=dp.end()){
            if(dp[idx].find(prev)!=dp[idx].end()){
                return dp[idx][prev];
            }
        }
        int res=INT_MAX;
        res=min(res,num+fun(idx+1,n,num,a,-1));
        for(auto x:a[idx]){
            if(x.first != prev){
                res=min(res,(num-x.second) + fun(idx+1,n,num,a,x.first));
            }
        }
        return dp[idx][prev]=res;
    }
    int minimumOperations(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        unordered_map<int,unordered_map<int,int>>mp;
        for(int j=0;j<m;j++){
            unordered_map<int,int>mp1;
            for(int i=0;i<n;i++){
                mp1[grid[i][j]]++;
            }
            mp[j]=mp1;
        }
        dp.clear();
        return fun(0,m,n,mp,-1);
    }
};