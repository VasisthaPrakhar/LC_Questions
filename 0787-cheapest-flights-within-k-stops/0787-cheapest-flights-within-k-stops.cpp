class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        vector<int>dist(n,INT_MAX);
        for(auto x:f){
            adj[x[0]].push_back({x[1],x[2]});
        }
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        queue<pair<int,int>>pq;
        pq.push({0,src});
        dist[src]=0;
        while(!pq.empty() && k>=0){
            int sz=pq.size();
            while(sz--){
                auto node=pq.front();
                pq.pop();
                for(auto x:adj[node.second]){
                    if(dist[x.first]>node.first+x.second){
                        dist[x.first]=node.first+x.second;
                        pq.push({dist[x.first],x.first});
                    }
                }
            }
            k--;
        }
        return dist[dst]==INT_MAX?-1:dist[dst];
    }
};