class Solution {
public:
    int minJumps(vector<int>& arr) {
          int n=arr.size();
        if(n==1){
            return 0;
        }
        unordered_map<int,vector<int>>m;
        for(int i=0;i<n;i++){
            m[arr[i]].push_back(i);
        }
        vector<int>vis(n,0);
        queue<int>q;
        q.push(0);
        int ans=0,f=0;
        while(!q.empty()){
            int s=q.size();
            while(s--){
                int node=q.front();
                q.pop();
                if(node==n-1){
                    return ans;
                }
                if(m.count(arr[node])){
                    for(auto x:m[arr[node]]){
                        if(!vis[x]){
                            q.push(x);
                            vis[x]=1;
                        }
                    }
                   m.erase(arr[node]); 
                }
                if(node>0){
                    if(!vis[node-1]){
                        q.push(node-1);
                        vis[node-1]=1;
                    }
                }
                if(node<n-1){
                    if(!vis[node+1]){
                        q.push(node+1);
                        vis[node+1]=1;
                    }
                }
            }
            ans++;
        }
        return 0;
    }
};