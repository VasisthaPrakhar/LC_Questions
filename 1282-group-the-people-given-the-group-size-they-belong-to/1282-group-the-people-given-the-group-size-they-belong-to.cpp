class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& g) {
        int n=g.size();
        vector<vector<int>>ans;
        unordered_map<int,vector<int>>m;
        for(int i=0;i<n;i++){
            m[g[i]].push_back(i);
            if(g[i]==m[g[i]].size()){
                ans.push_back(m[g[i]]);
                m.erase(g[i]);
            }
        }
        return ans;
    }
};