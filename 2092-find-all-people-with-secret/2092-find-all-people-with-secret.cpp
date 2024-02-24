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
        }        else if(rank[v]<rank[u]){
            par[v]=u;
        }else{
            par[v]=u;
            rank[u]++;
        }
    }
    // void fun1(vector<int>adj[],int node,vector<int>&vis){
    //     vis[node]=1;
    //     for(auto x:adj[node]){
    //         if(!vis[x]){
    //             fun1(adj,x,vis);  
    //         }
    //     }
    // }
    // void fun(vector<pair<int,int>>&a,int n,vector<int>&ans){
    //     vector<int>adj[n],vis(n,0);
    //     unordered_set<int>s;
    //     for(auto x:a){
    //         adj[x.first].push_back(x.second);
    //         adj[x.second].push_back(x.first);
    //         s.insert(x.first);
    //         s.insert(x.second);
    //     }
    //     for(auto x:s){
    //         if(ans[x] && !vis[x]){
    //             fun1(adj,x,vis);
    //         }
    //     }
    //     for(int i=0;i<n;i++){
    //         if(vis[i])
    //             ans[i]=1;
    //     }
    // }
    vector<int> findAllPeople(int n, vector<vector<int>>& me, int f) {
        map<int,vector<pair<int,int>>>m;
        for(auto x:me){
            m[x[2]].push_back({x[0],x[1]});
        }
        set<int>s;
        vector<int>res,rank(n,0),par(n,0);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
        unionn(0,f,par,rank);
        for(auto x:m){
            for(auto y:x.second){
                unionn(y.first,y.second,par,rank);
            }
            for(auto y:x.second){
                if(findpar(y.first,par)!=par[0]){
                    rank[y.first]=0;
                    par[y.first]=y.first;
                    rank[y.second]=0;
                    par[y.second]=y.second;
                }
            }
        }
        res.push_back(0);
        for(int i=1;i<n;i++){
            if(findpar(i,par)==par[0]){
                res.push_back(i);
            }
        }
        return res;
    }
};