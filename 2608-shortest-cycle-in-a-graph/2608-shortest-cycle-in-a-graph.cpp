class Solution {
public:
    int bfs(int s,int n,vector<int>adj[],vector<int>&vis){
        queue<pair<int,vector<int>>>q;
        q.push({s,{-1}});
        vis[s]=1;
        map<int,vector<int>>mp;
        mp[s]={-1};
        int ans=INT_MAX;
        while(!q.empty()){
            int node=q.front().first;
            vector<int> arr=q.front().second;
            int par=arr.back();
            q.pop();
            for(auto x:adj[node]){
                if(!vis[x]){
                    vis[x]=1;
                    vector<int>b=arr;
                    b.push_back(node);
                    mp[x]=b;
                    q.push({x,b});
                }else if(par!=x){
                    set<int>s;
                    for(auto y:arr){
                        s.insert(y);
                    }
                    for(auto y:mp[x]){
                        if(s.find(y)!=s.end()){
                            s.erase(y);
                        }else{
                            s.insert(y);
                        }
                    }
                    ans=min(ans,(int)s.size()+3);
                }
            }
        }
        //cout<<ans<<" ";
        return ans==INT_MAX?-1:ans;
    }
    int findShortestCycle(int n, vector<vector<int>>& ed) {
        vector<int>adj[n];
        for(auto x:ed){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int>vis(n,0);
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int k=bfs(i,n,adj,vis);
                if(k!=-1){
                    ans=min(ans,k);
                }
            }
        }
        cout<<endl;
        return ans==INT_MAX?-1:ans;
    }
};