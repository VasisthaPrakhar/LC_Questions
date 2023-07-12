class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        int n=g.size();
        unordered_map<int,set<int>>adj;
        vector<int>ind(n,0),ans;
        for(int i=0;i<n;i++){
            for(auto x:g[i]){
                adj[x].insert(i);
                ind[i]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(ind[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto x:adj[node]){
                ind[x]--;
                if(ind[x]==0){
                    q.push(x);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};