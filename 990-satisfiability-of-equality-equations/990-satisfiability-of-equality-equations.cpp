class Solution {
public:
    int parent[202];
    int rank[202];
    void makeSet(int n){
        for(int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=0;
        }
    }
    int findPar(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findPar(parent[node]);
    }
    void unionn(int u, int v){
        u=findPar(u);
        v=findPar(v);
        if(rank[u]<rank[v]){parent[u]=v;}
        else if(rank[u]>rank[v]){parent[v]=u;}
        else{
            parent[v]=u;
            rank[u]++;
        }
    }

    bool equationsPossible(vector<string>& eq) {
        int n=eq.size();
        makeSet(26);
        int flag=0;
        for(int i=0;i<n;i++){
            if(eq[i][1]=='='){
                int u=(eq[i][0]-'a');
                int v=(eq[i][3]-'a');
                unionn(u,v);
            }            
        }
        for(int i=0;i<n;i++){
            int u=(eq[i][0]-'a');
            int v=(eq[i][3]-'a');
            if(eq[i][1]=='!' && findPar(u)==findPar(v)){
                return false;
            }
        }
        
        return true;
    }
};