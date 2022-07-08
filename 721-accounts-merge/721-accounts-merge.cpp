class Solution {
public:
    void dfs(string &s,unordered_map<string,vector<string>>&adj,vector<string>&res,unordered_set<string>&vis){
        vis.insert(s);
        res.push_back(s);
        for(auto x:adj[s]){
            if(vis.find(x)==vis.end()){
                dfs(x,adj,res,vis);
            }
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>adj;
        unordered_set<string>vis;
        int n=acc.size();
        for(int i=0;i<n;i++){
            for(int j=2;j<acc[i].size();j++){
                adj[acc[i][j-1]].push_back(acc[i][j]);
                adj[acc[i][j]].push_back(acc[i][j-1]);
            }
        }
        for(int i=0;i<n;i++){
            if(vis.find(acc[i][1])==vis.end()){
                vector<string>res;
                res.push_back(acc[i][0]);
                dfs(acc[i][1],adj,res,vis);
                sort(res.begin()+1,res.end());
                ans.push_back(res);
            }
        }
        return ans;
    }
};