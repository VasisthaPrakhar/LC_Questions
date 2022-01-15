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
        vis[0]=1;
        int ans=0;
        while(!q.empty()){
            int s=q.size();
            while(s--){
                int node=q.front();
                q.pop();
                if(node==n-1){
                    return ans;
                }
                vector<int>&a=m[arr[node]];
                a.push_back(node-1);
                a.push_back(node+1);
                for(auto x:a){
                    if(x>=0 && x<n && !vis[x]){
                        vis[x]=1;
                        q.push(x);
                    }
                }
                a.clear();
            }
            ans++;
        }
        return 0;
    }
};