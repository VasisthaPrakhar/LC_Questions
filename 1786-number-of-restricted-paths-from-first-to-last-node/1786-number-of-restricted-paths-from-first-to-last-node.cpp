class Solution {
public:
    int mod=1000000007;
    int dfs(int n,vector<pair<int,int>>adj[],vector<int>&dist,vector<int>&dp){
        if(n==1){
            return 1;
        }
        if(dp[n]==-1){
            int sum=0;
            for(auto x:adj[n]){
                if(dist[n]<dist[x.first]){
                    sum=(sum%mod + dfs(x.first,adj,dist,dp)%mod)%mod;
                }
            }
            dp[n]=sum%mod;
        }
        return dp[n];
    }
    int countRestrictedPaths(int n, vector<vector<int>>& ed) {
        int m=ed.size();
        vector<pair<int,int>>adj[n+1];
        for(auto x:ed){
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }
        set<pair<int,int>>s;
        vector<int>dist(n+1,INT_MAX);
        s.insert({0,n});
        dist[n]=0;
        while(!s.empty()){
            auto node=*s.begin();
            s.erase(node);
            for(auto x:adj[node.second]){
                if(dist[x.first]>dist[node.second]+x.second){
                    dist[x.first]=dist[node.second]+x.second;
                    s.insert({dist[x.first],x.first});
                }
            }
        }
        for(auto x:dist){
            cout<<x<<" ";
        }
        vector<int>dp(n+1,-1);
        return dfs(n,adj,dist,dp);
    }
};