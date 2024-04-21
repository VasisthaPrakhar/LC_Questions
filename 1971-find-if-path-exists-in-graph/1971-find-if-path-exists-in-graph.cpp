class Solution {
public:
     int findpar(int u,vector<int>&par){
        if(u==par[u])
            return u;
        return findpar(par[u],par);
    }
    void unionn(int u,int v,vector<int>&par,vector<int>&rank){
        u=findpar(u,par);
        v=findpar(v,par);
        if(rank[u]<rank[v]){
            par[u]=v;
        }else if(rank[v]<rank[u]){
            par[v]=u;
        }else{
            par[v]=u;
            rank[u]++;
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int src, int dest) {
        // vector<int>adj[n];
        // for(auto &x:edges){
        //     adj[x[0]].push_back(x[1]);
        //     adj[x[1]].push_back(x[0]);
        // }
        // queue<int>q;
        // vector<int>vis(n,0);
        // vis[src]=1;
        // q.push(src);
        // while(!q.empty()){
        //     int node=q.front();
        //     q.pop();
        //     if(node == dest){
        //         return true;
        //     }
        //     for(auto x:adj[node]){
        //         if(!vis[x]){
        //             q.push(x);
        //             vis[x]=1;
        //         }
        //     }
        // }
        vector<int>par(n),rank(n,0);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
        rank[src]=1000;
        for(auto &x:edges){
           unionn(x[0],x[1],par,rank);
          // unionn(x[1],x[0],par,rank);
        }
        // for(auto &x:edges){
        //    unionn(x[0],x[1],par,rank);
        //   // unionn(x[1],x[0],par,rank);
        // }
        if(findpar(dest,par)==src){
            return true;
        }
        return false;        
    }
};