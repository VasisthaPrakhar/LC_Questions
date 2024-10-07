class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& in) {
        map<int,set<int>>adj;
        for(auto x:in){
            adj[x[0]].insert(x[1]);
        }
        queue<int>q;
        q.push(k);
        vector<int>vis(n,0);
        unordered_set<int>s;
        vis[k]=1;
        s.insert(k);
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            for(auto x:adj[node]){
                if(!vis[x]){
                    q.push(x);
                    s.insert(x);
                    vis[x]=1;
                }
            }
        }
        vector<int>ans;
        int flag=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                for(auto x:adj[i]){
                    if(s.find(x)!=s.end()){
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    ans.push_back(i);
                }
            }
        }
        vector<int>res;
        for(int i=0;i<n;i++){
            res.push_back(i);
        }
        return flag==1?res:ans;
    }
};