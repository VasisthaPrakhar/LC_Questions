class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int, double>>adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        vector<double>dist(n,-1);
        queue<pair<int,double>>q;
        q.push({start,1});
        dist[start]=1;
         while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                auto node=q.front();
                q.pop();
                for(auto x: adj[node.first]){
                    if((x.second * node.second) > dist[x.first]){
                        dist[x.first]=(x.second * node.second);
                        q.push({x.first,node.second*x.second});
                    }
                }
            }
        }
        if(dist[end]==-1)
        return 0;
        else
            return dist[end];
        
    }
};