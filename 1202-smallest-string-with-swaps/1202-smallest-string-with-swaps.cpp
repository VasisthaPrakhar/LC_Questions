class Solution {
public:
    void dfs(vector<int>adj[],int node,string &s,vector<int>&vis,map<int,multiset<char>>&st,int idx){
        vis[node]=idx;
        st[idx].insert(s[node]);
        for(auto x:adj[node]){
            if(vis[x]==-1){
                dfs(adj,x,s,vis,st,idx);
            }
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.length();
        vector<int>vis(n,-1),adj[n];
        for(auto x:pairs){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        map<int,multiset<char>>st;
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                dfs(adj,i,s,vis,st,i);
            }
        }
        for(int i=0;i<n;i++){
            auto it=st[vis[i]].begin();
            s[i]=*it;
            st[vis[i]].erase(it);
        }
        return s;
    }
};