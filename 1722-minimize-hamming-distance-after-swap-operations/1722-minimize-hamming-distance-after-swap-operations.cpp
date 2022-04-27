class Solution {
public:
    int cmp(multiset<int>&a, multiset<int>&b){
        int ans=0;
        for(auto x:a){
            if(b.find(x)==b.end()){
                ans++;
            }else{
                b.erase(b.find(x));
            }
        }
        return ans;
    }
    void dfs(vector<int>adj[],int node,vector<int> &s,vector<int>&vis,map<int,multiset<int>>&st,int idx){
        vis[node]=idx;
        st[idx].insert(s[node]);
        for(auto x:adj[node]){
            if(vis[x]==-1){
                dfs(adj,x,s,vis,st,idx);
            }
        }
    }
    int minimumHammingDistance(vector<int>& s, vector<int>& target, vector<vector<int>>& p) {
        int n=s.size();
        vector<int>vis(n,-1),adj[n];
        for(auto x:p){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        map<int,multiset<int>>st,m;
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                dfs(adj,i,s,vis,st,i);
            }
        }
        for(int i=0;i<n;i++){
            m[vis[i]].insert(target[i]);
        }
        int ans=0;
        for(auto x:m){
            // for(auto y:x.second){
            //     cout<<y<<" ";
            // }
            // cout<<"|| ";
            // for(auto y:st[x.first]){
            //     cout<<y<<" ";
            // }
            // cout<<endl;
            ans+=cmp(x.second,st[x.first]);
        }
        return ans;
    }
};