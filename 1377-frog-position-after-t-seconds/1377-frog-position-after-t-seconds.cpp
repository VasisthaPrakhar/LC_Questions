class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& ed, int t, int target) {
        if(t==0){
            return target==1?1:0;
        }
        vector<int>adj[n+1];
        for(auto x:ed){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        queue<pair<int,double>>q;
        vector<int>vis(n+1,0);
        long double ans=1.0000000000000000;
        q.push({1,ans});
        vis[1]=1;
        while(!q.empty() && t>=0){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto node=q.front();
                q.pop();
                vis[node.first]=1;
                double k=0;
                for(auto x:adj[node.first]){
                    if(!vis[x])
                        k=k+1;
                }
                if(t>=0 && node.first==target){
                    if(t>0 && k==0)
                        return node.second;
                    if(t==0)
                        return node.second;
                }
                double c=node.second/k;
                for(auto x:adj[node.first]){
                    if(!vis[x])
                    q.push({x,c});
                }
            }
            t--;
        }
        return 0.0000000000000000;
    }
};