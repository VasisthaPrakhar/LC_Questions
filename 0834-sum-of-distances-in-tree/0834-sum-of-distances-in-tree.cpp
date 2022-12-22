class Solution {
public:
    void dfs(int node,int p,vector<int> adj[],vector<int> &ans,vector<int> &cnt){
        for(auto& x:adj[node]){
            if(x!=p){
                dfs(x,node,adj,ans,cnt);
                cnt[node]+=cnt[x];
                ans[node]+=ans[x]+cnt[x];
            }
        }
    }
    void dfs2(int node,int p,vector<int> adj[],vector<int> &ans,vector<int> &cnt, int size){
        for(auto& x:adj[node]){
            if(x!=p){
                ans[x]+=ans[node]+size-(2*cnt[x])-ans[x];
                dfs2(x,node,adj,ans,cnt,size);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& e) {
        vector<int> adj[n];
        vector<int> ans(n,0);
        vector<int> cnt(n,1);
        for(auto x:e){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<adj[i].size();j++){
        //         cout<<adj[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
//         for(int i=0;i<n;i++){
//             queue<int> q;
//             q.push(i);
//             int sum=0;
//             int lev=0-1;
//             vector<int> vis(n,0);
//             vis[i]=1;
            
//             while(!q.empty()){
//                 ++lev;
//                 int p=q.size();
//                 for(int m=0;m<p;m++){
//                     //cout<<q.front()<<" ";
//                     int node=q.front();
//                     q.pop();
//                     sum+=lev;
//                    // cout<<sum<<" ";
//                     for(auto it:adj[node]){
//                         if(!vis[it]){
//                             q.push(it);
//                             vis[it]++;
//                         }
//                     }
//                 }
//             }
//             ans[i]=sum;
//             //cout<<endl;
//         }
        dfs(0,-1,adj,ans,cnt);
        dfs2(0,-1,adj,ans,cnt,n);
        return ans;
    }
};