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
        //cout<<u<<" "<<v<<endl;
        if(rank[u]<rank[v]){
            par[u]=v;
        }else if(rank[v]<rank[u]){
            par[v]=u;
        }else{
            par[v]=u;
            rank[u]++;
        }
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& ed, vector<vector<int>>& qu) {
        int m=qu.size();
        for(int i=0;i<m;i++){
            qu[i].push_back(i);
        }
        sort(qu.begin(),qu.end(),[](vector<int>&a,vector<int>&b)->bool{
            return a[2]<b[2];
        });
        sort(ed.begin(),ed.end(),[](vector<int>&a,vector<int>&b)->bool{
            return a[2]<b[2];
        });
        vector<int>par(n),rank(n,0);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
        int i=0;
        vector<bool>ans(m,false);
        for(auto x:qu){
            while(i<ed.size() && ed[i].back()<x[2]){
                unionn(ed[i][0],ed[i][1],par,rank);
                i++;
            }
            // for(auto y:par){
            //     cout<<y<<" ";
            // }
            // cout<<endl;
            ans[x[3]]=findpar(x[0],par)==findpar(x[1],par);
        }
        return ans;
    }
};