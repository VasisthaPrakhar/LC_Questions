#pragma GCC optimize("fast")
static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();
class Solution {
public:
    int ans[2]={-1};
    int findpar(int u,vector<int>&par){
        if(u==par[u])
            return u;
        return findpar(par[u],par);
    }
    void unionn(int u,int v,vector<int>&par,vector<int>&rank){
        int a=u,b=v;
        u=findpar(u,par);
        v=findpar(v,par);
        if(u==v){
            //cout<<a<<" "<<b;
            ans[0]=a;
            ans[1]=b;
        }
        if(rank[u]<rank[v]){
            par[u]=v;
        }else if(rank[v]<rank[u]){
            par[v]=u;
        }else{
            par[v]=u;
            rank[u]++;
        }
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& ed) {
        int n=ed.size();
        vector<int>par(n+1);
        map<int,vector<int>>m;
        int cnt=0;
        for(auto x:ed){
            m[x[1]].push_back(x[0]);
            if(m[x[1]].size()>1){
                cnt=x[1];
            }
        }
        if(cnt==0){
            for(int i=0;i<=n;i++){
                par[i]=i;
            }
            vector<int>rank(n+1,0);
            ans[0]=-1,ans[1]=-1;
            for(auto &it:ed){
                unionn(it[0],it[1],par,rank);
            }
            return {ans[0],ans[1]};
        }
        vector<int>res(2);
        for(int i=0;i<2;i++){
            for(int i=0;i<=n;i++){
                par[i]=i;
            }
            vector<int>rank(n+1,0);
            ans[0]=-1,ans[1]=-1;
            for(auto &it:ed){
                if(it[0]!=m[cnt][i] || it[1]!=cnt)
                    unionn(it[0],it[1],par,rank);
            }
            if(ans[0]==-1 && ans[1]==-1){
                res[1]=cnt;
                res[0]=m[cnt][i];
            }
        }
        return res;
    }
};