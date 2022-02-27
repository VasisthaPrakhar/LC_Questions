// class Solution {
// public:
//     map<char,int> dfs(vector<int>adj[],vector<int>&ans,string &s,int par,int node){
//         if(adj[node].size()==0){
//             map<char,int>m;
//             m[s[node]]++;
//             ans[node]=1;
//             return m;
//         }
//         map<char,int>m;
//         for(auto x:adj[node]){
//             if(x!=par){
//                 auto mp=dfs(adj,ans,s,node,x);
//                 for(auto x:mp){
//                     m[x.first]+=x.second;
//                 }
//             }
//         }
//         m[s[node]]++;
//         ans[node]=m[s[node]];
//         return m;
//     }
//     vector<int> countSubTrees(int n, vector<vector<int>>& ed, string lab) {
//         vector<int>adj[n];
//         for(int i=0;i<n-1;i++){
//             adj[ed[i][0]].push_back(ed[i][1]);
//             adj[ed[i][1]].push_back(ed[i][0]);
//         }
//         vector<int>ans(n,0);
//         dfs(adj,ans,lab,-1,0);
//         return ans;
//     }
// };
class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> res(n,0);
        vector<bool> vis(n,false);
        vector<vector<int>> g(n+1,vector<int>()); // Graph that stores vertices and edges
        for(int i=0;i<n-1;i++){
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        helper(g, labels, 0, res, vis);
        return res;
    }
private:
    vector<int> helper(vector<vector<int>> &g, string &labels, int u,vector<int>& res, vector<bool> &vis){
        vis[u] = true; // marking node as visited ----concept from DFS 
        vector<int> resultantFreqMap(26,0); // initializing frequency vector to store count of labels
        resultantFreqMap[labels[u]-'a'] = 1; 
        for(auto v:g[u]){
            if(!vis[v]){ // if node is not visited.
                vector<int> b = helper(g, labels, v, res, vis); // calculating frequency vector for children.
                for(int i=0;i<26;i++)
                    resultantFreqMap[i] +=b[i]; // adding frequency to parent 
            }
        }
        res[u] = resultantFreqMap[labels[u]-'a']; // answer for node u will be frequency calculated before.
        vis[u] = false; 
        return resultantFreqMap;
    }
};