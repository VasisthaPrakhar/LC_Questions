class Solution {
public:
    int findCenter(vector<vector<int>>& ed) {
        int n=ed.size();
        unordered_map<int,vector<int>>adj;
        for(auto x:ed){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        for(auto x:adj){
            if(x.second.size()>1){
                return x.first;
            }
        }
        return -1;
    }
};