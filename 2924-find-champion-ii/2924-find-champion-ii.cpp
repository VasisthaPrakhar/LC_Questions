class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        int m=edges.size();
        vector<int>adj[n],ind(n,0),a;
        
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            ind[edges[i][1]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(ind[i]==0){
                q.push(i);
            }
        }
        if(q.size()>1){
            return -1;
        }
        int c=0;
        while(!q.empty()){
            int node =q.front();
            q.pop();
            a.push_back(node);
            c++;
            for(auto it:adj[node]){
                ind[it]--;
                if(ind[it]==0){
                    q.push(it);
                }
            }
        }
        // if(c>n){
        //     return -1;
        // }
        return a[0];
    }
};