#pragma GCC optimize("fast")
static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();
class Solution {
public:
    struct node{
        int u;
        int v;
        int wt;
        node(int u1,int v1,int w1){
            u=u1;
            v=v1;
            wt=w1;
        }
    };
    bool comp(node &a,node &b){
        return a.wt<b.wt;
    }
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
    int minCostConnectPoints(vector<vector<int>>& p) {
        int n=p.size();
        vector<node>adj;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                adj.push_back(node(i,j,(abs(p[i][0]-p[j][0])+abs(p[i][1]-p[j][1]))));    
            }
        }
        sort(adj.begin(),adj.end(),[](node &a,node &b)->bool{
            return a.wt<b.wt;
        });
        vector<int>par(n),rank(n,0);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
        int cost=0;
        for(auto it:adj){
            if(findpar(it.v,par)!=findpar(it.u,par)){
                cost+=it.wt;
                unionn(it.u,it.v,par,rank);
            }
        }
        return cost;
    }
};