class Solution {
public:
    int numOfMinutes(int n, int h, vector<int>& m, vector<int>& t) {
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            if(m[i]!=-1)
            adj[m[i]].push_back(i);
        }
        queue<pair<int,int>>q;
        q.push({h,0});
        int ans=0;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            int k=t[node.first]+node.second;
            ans=max(ans,k);
            for(auto x:adj[node.first]){
                q.push({x,k});
            }
        }
        return ans;
    }
};