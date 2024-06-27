class Solution {
public:
    int findCenter(vector<vector<int>>& ed) {
        int n=ed.size();
        unordered_map<int,int>adj;
        for(auto &x:ed){
            adj[x[0]]++;
            adj[x[1]]++;
        }
        for(auto &x:adj){
            if(x.second>1){
                return x.first;
            }
        }
        return -1;
    }
};