class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int src, int dest) {
        vector<int>adj[n];
        for(auto &x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        queue<int>q;
        vector<int>vis(n,0);
        vis[src]=1;
        q.push(src);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            if(node == dest){
                return true;
            }
            for(auto x:adj[node]){
                if(!vis[x]){
                    q.push(x);
                    vis[x]=1;
                }
            }
        }
        return false;        
    }
};