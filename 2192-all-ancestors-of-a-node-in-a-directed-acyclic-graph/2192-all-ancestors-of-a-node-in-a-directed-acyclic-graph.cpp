class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& ed) {
        int m=ed.size();
        vector<int>adj[n],ind(n,0),vis(n,0);
        for(int i=0;i<m;i++){
            adj[ed[i][0]].push_back(ed[i][1]);
            ind[ed[i][1]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(ind[i]==0){
                q.push(i);
            }
        }
        map<int,set<int>>mp;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto x:adj[node]){
                ind[x]--;
                if(ind[x]==0){
                    q.push(x);
                }
                for(auto y:mp[node]){
                    mp[x].insert(y);
                }
                mp[x].insert(node);
            }
        }
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            vector<int>temp;
            if(mp.find(i)!=mp.end()){
                for(auto x:mp[i]){
                    temp.push_back(x);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};