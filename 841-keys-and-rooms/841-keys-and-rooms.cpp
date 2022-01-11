static const auto Initialize = []{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int parent[10000];
    int rank[10000];
    void makeSet(int n){
        for(int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=0;
        }
    }
    int findpar(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findpar(parent[node]);
    }
    void unionn(int u,int v){
        u=findpar(u);
        v=findpar(v);
        if(rank[u]<rank[v]){
            parent[u]=v;
        }
        else if(rank[v]<rank[u]){
            parent[v]=u;
        }else{
            parent[v]=u;
            rank[u]++;
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        makeSet(n);
        vector<bool>vis(n,false);
        vis[0]=true;
      for(int k=0;k<7;k++){
          for(int i=0;i<n;i++){
            if(vis[i])
            for(int j=0;j<rooms[i].size();j++){
                unionn(i,rooms[i][j]);
                vis[rooms[i][j]]=true;
            }
        }
      }
        int flag=0;
        for(int i=1;i<n;i++){
            if(parent[i]==i){
                flag=1;
                break;
            }
        }
        if(flag){
            return false;
        }
        return true;
    }
};