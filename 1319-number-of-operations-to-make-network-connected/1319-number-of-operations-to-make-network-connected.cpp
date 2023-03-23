class Solution {
public:
     int parent[100001];
    void makeSet(int n){
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int findPar(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findPar(parent[node]);
    }
    bool unionn(int u, int v){
        u=findPar(u);
        v=findPar(v);
        if(v==u){
            return false;
        }
        parent[v]=u;
        return true;
    }
    int makeConnected(int n, vector<vector<int>>& c) {
        makeSet(n);
        int count=0,cnt=0;
        for(int i=0;i<c.size();i++){
            if(!unionn(c[i][0],c[i][1])){
                count++;
            }
        }
        for(int i=0;i<n;i++){
            if(parent[i]==i){
                cnt++;
            }
        }
        cnt--;
        if(cnt>count){
            return -1;
        }
        else
        return cnt;
    }
};