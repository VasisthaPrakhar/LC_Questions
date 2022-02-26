class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& ed, int t, int target) {
        vector<int>adj[n+1];
        for(auto x:ed){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        queue<pair<int,double>>q;
        vector<int>vis(n+1,0);
        double ans=1;
        q.push({1,ans});
        vis[1]=1;
        while(!q.empty() && t>=0){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto node=q.front();
                q.pop();
                vis[node.first]=1;
                int k=0;
                for(auto x:adj[node.first]){
                    if(!vis[x])
                        k++;
                }
                if(t>=0 && node.first==target){
                    if(t>0 && k==0)
                        return node.second;
                    if(t==0)
                        return node.second;
                }
                double c=0;
                if(k>0)
                    c=node.second/(double)k;
                for(auto x:adj[node.first]){
                    if(!vis[x])
                    q.push({x,c});
                }
            }
            t--;
        }
        return 0;
    }
};