class Graph {
    typedef long long int ll;
    private: vector<pair<ll,int>>adj[101];
    int m;
    
public:
    Graph(int n, vector<vector<int>>& ed) {
        // a.resize(n+1,vector<long long int>(n+1,INT_MAX));
        // for(int i=0;i<=n;i++){
        //     a[i][i]=0;
        // }
        // for(auto x:ed){
        //     a[x[0]][x[1]]=x[2];
        // }
        // m=n;
        // for (int k=0;k<n;k++) {
        //     for (int i=0;i<n;i++) {
        //         for (int j=0;j<n;j++) {
        //             if (a[i][j]>(a[i][k] + a[k][j])&&(a[k][j]!=INT_MAX && a[i][k]!=INT_MAX)){
        //                 a[i][j] = a[i][k] + a[k][j];
        //             }
        //         }
        //     }
        // }
        // for(auto x:a){
        //     for(auto y:x){
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }
        for(auto x:ed){
            adj[x[0]].push_back({x[1],x[2]});
        }
        m=n;
    }
    
    void addEdge(vector<int> ed) {
        // a[ed[0]][ed[1]]=ed[2];
        // for (int k=0;k<m;k++) {
        //     for (int i=0;i<m;i++) {
        //         for (int j=0;j<m;j++) {
        //             if (a[i][j]>(a[i][k] + a[k][j])&&(a[k][j]!=INT_MAX && a[i][k]!=INT_MAX)){
        //                 a[i][j] = a[i][k] + a[k][j];
        //             }
        //         }
        //     }
        // }
        adj[ed[0]].push_back({ed[1],ed[2]});
    }
    
    int shortestPath(int n1, int n2) {
        vector<ll>dis(m+1,LLONG_MAX);
        dis[n1]=0;
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
        pq.push({0,n1});
        while(!pq.empty()){
            ll d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto x:adj[node]){
                if(dis[x.first]>dis[node]+x.second){
                    dis[x.first]=dis[node]+x.second;
                    pq.push({dis[x.first],x.first});
                }
            }
        }
        return dis[n2]==LLONG_MAX?-1:dis[n2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */