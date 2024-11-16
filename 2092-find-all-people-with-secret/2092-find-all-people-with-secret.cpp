class Solution {
public:
    int findpar(int u,vector<int>&par){
        if(u==par[u]){
            return u;
        }
        return findpar(par[u],par);
    }
    void unionn(int u,int v,vector<int>&par, vector<int>&rank){
        u=findpar(u,par);
        v=findpar(v,par);
        if(rank[u]>rank[v]){
            par[v]=u;
        }else if(rank[v]>rank[u]){
            par[u]=v;
        }else{
            par[v]=u;
            rank[u]++;
        }
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& me, int f) {
        vector<int>par(n,0),rank(n,0);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
        //rank[0]=100001;
        map<int,vector<pair<int,int>>>adj;
        for(auto x:me){
            adj[x[2]].push_back({x[0],x[1]});
        }
        unionn(0,f,par,rank);
        for(auto x:adj){
            for(auto y:x.second){
                //if(findpar(y.first,par)==0 || findpar(y.second,par)==0)
                    unionn(y.first,y.second,par,rank);
            }
            for(auto y:x.second){
                if(findpar(y.first,par)!=par[0]){
                    par[y.first]=y.first;
                    rank[y.first]=0;
                    par[y.second]=y.second;
                    rank[y.second]=0;
                }
            }
        }
        vector<int>ans;
        ans.push_back(0);
        for(int i=1;i<n;i++){
            if(findpar(i,par)==findpar(0,par)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};