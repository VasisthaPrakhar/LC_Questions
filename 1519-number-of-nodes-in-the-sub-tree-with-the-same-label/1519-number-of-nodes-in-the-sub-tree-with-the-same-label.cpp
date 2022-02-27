class Solution {
public:
    vector<int> dfs(vector<int>adj[],vector<int>&ans,string &s,int par,int node){
        if(adj[node].size()==0){
            vector<int>m(26,0);
            m[s[node]-'a']++;
            ans[node]=1;
            return m;
        }
        vector<int>m(26,0);
        for(auto x:adj[node]){
            if(x!=par){
                auto mp=dfs(adj,ans,s,node,x);
                for(int i=0;i<26;i++){
                    m[i]+=mp[i];
                }
            }
        }
        m[s[node]-'a']++;
        ans[node]=m[s[node]-'a'];
        return m;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& ed, string lab) {
        vector<int>adj[n];
        for(int i=0;i<n-1;i++){
            adj[ed[i][0]].push_back(ed[i][1]);
            adj[ed[i][1]].push_back(ed[i][0]);
        }
        vector<int>ans(n,0);
        dfs(adj,ans,lab,-1,0);
        return ans;
    }
};