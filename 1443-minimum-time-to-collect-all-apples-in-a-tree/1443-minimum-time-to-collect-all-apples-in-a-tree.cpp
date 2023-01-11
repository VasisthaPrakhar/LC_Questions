class Solution {
public:
    int fun(vector<int>adj[],vector<int>&vis,vector<bool>& ha,int node){
        vis[node]=1;
        int ans=0;
        for(auto x:adj[node]){
            if(vis[x]==0)
                ans+=fun(adj,vis,ha,x);
        }
        if(ans>0 || ha[node]){
            ans+=2;
        }
        return ans;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& ha) {
       vector<int>adj[n];
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int>vis(n,0);
        int ans=fun(adj,vis,ha,0);
        if(ans>0){
            ans-=2;
        }
        return ans;
    }
};