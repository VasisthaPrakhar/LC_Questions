class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& r, vector<int>& t) {
        vector<int>adj[n+1],ind(n+1,0),dist(n+1,0);
        for(int i=0;i<r.size();i++){
            adj[r[i][0]].push_back(r[i][1]);
            ind[r[i][1]]++;
        }
        queue<int>q;
        for(int i=1;i<=n;i++){
            if(ind[i]==0){
                q.push(i);
                dist[i]=t[i-1];
            }
        }
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            for(auto x:adj[node]){
                ind[x]--;
                dist[x]=max(dist[x],dist[node]);
                if(ind[x]==0){
                    dist[x]+=t[x-1];
                    q.push(x);
                }
            }
        }
        return *max_element(dist.begin(),dist.end());
    }
};