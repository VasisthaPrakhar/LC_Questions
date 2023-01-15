class Solution {
    vector<map<int, int>> mp;
    vector<vector<int>> graph;
    vector<int> flag;
    
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        mp.resize(n);
        graph.resize(n);
        
        for (auto &e: edges) {
            int u = e[0], v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        int ret = 0;
        flag.resize(n, 0);
        dfs(ret, 0, vals);
        
        return ret + n;
    }
    
    void dfs(int &count, int u, vector<int>& vals) {
        flag[u] = 1;
        
        for (auto &v: graph[u]) {
            if (flag[v] == 1) continue;
            
            int cnt = 0;
            dfs(cnt, v, vals);
            count += cnt;
            
            auto it = mp[v].lower_bound(vals[u]);
            mp[v].erase(mp[v].begin(), it);
            
            if (mp[u].size() < mp[v].size()) {
                swap(mp[u], mp[v]);    
            }
            // end of performance tuning
            
            for (auto &it: mp[v]) {
                count += mp[u][it.first] * it.second; // paths with end points in sub-trees that go by node u
                mp[u][it.first] += it.second;
            }
        }
        count += mp[u][vals[u]]; // paths with one end at node u
        ++mp[u][vals[u]]; // node u as a path
    }
};