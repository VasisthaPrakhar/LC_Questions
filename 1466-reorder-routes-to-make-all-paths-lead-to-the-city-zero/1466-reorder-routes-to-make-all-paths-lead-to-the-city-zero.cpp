class Solution {
public:
    int minReorder(int n, vector<vector<int>>& co) {
        int m=co.size();
        vector<pair<int,int>>adj[n];
        for(int i=0;i<m;i++){
            adj[co[i][0]].push_back({co[i][1],1});
            adj[co[i][1]].push_back({co[i][0],0});
        }
        vector<int>vis(n,0);
        vis[0]=1;
       queue<int>q;
        int ans=0;
        q.push(0);
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            for(auto x:adj[node]){
                if(!vis[x.first]){
                    vis[x.first]=1;
                    if(x.second==1){
                        ans++;
                    }
                    q.push(x.first);
                }
            }
        }
        return ans;
    }
};