class Solution {
public:
    int networkDelayTime(vector<vector<int>>& t, int n, int k) {
        int s=t.size();
        vector<pair<int,int>>adj[n+1];
        for(int i=0;i<s;i++){
            adj[t[i][0]].push_back({t[i][1],t[i][2]});
        }
        vector<int>dis(n+1,INT_MAX);
        //priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        set<pair<int,int>>q;
        q.insert({0,k});
        dis[k]=0;
        while(!q.empty()){
            auto node=*q.begin();
            q.erase(node);
            for(auto x:adj[node.second]){
                if(dis[x.first]>dis[node.second]+x.second){
                    dis[x.first]=dis[node.second]+x.second;
                    q.insert({dis[x.first],x.first});
                }
            }
        }
        dis[0]=-1;
        int ans=*max_element(dis.begin(),dis.end());
        return ans==INT_MAX?-1:ans;
    }
};