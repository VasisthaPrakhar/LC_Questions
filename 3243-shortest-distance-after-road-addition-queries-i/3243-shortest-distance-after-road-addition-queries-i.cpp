class Solution {
public:
    int fun(vector<int>adj[],int n){
        queue<int>q;
        q.push(0);
        vector<int>vis(n,0);
        int ans=0;
        vis[0]=1;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto node=q.front();
                q.pop();
                if(node==n-1){
                    return ans;
                }
                for(auto x:adj[node]){
                    if(!vis[x]){
                        vis[x]=1;
                        q.push(x);   
                    }
                }
            }
            ans++;
        }
        return ans;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& qu) {
        int m=qu.size();
        vector<int>adj[n],ans;
        for(int i=0;i<n-1;i++){
            adj[i].push_back(i+1);
        }
        for(int i=0;i<m;i++){
            adj[qu[i][0]].push_back(qu[i][1]);
            ans.push_back(fun(adj,n));
        }
        return ans;
    }
};