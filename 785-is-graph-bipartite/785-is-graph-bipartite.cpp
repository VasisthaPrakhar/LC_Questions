class Solution {
public:
        bool bpbfs(int src,vector<int> adj[],vector<int> &color){
        queue<int>q;
        q.push(src);
        color[src]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto x:adj[node]){
                if(color[x]==-1){
                    color[x]=2-(color[node]-1);
    //                cout<<"Debug!!!!"<<endl;
                    q.push(x);
                }
                else if(color[x]==color[node]){
                    return false;
                }
            }
        }
        return true;
    }
    bool checkbp(vector<int> adj[],int n,vector<int> &color){
        for (int i = 0; i < n; ++i) {
            if(color[i]==-1){
                if(!bpbfs(i,adj,color)){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>adj[n];
        for (int i = 0; i < graph.size(); ++i) {
            for (int j = 0; j < graph[i].size(); ++j) {
                adj[i].push_back(graph[i][j]);
            }
        }
        vector<int>color(n,-1);
        if(checkbp(adj,n,color)){
           return true;
        }
        return false;
    }
};