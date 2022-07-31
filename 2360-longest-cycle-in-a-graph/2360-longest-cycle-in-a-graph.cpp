class Solution {
public:
    bool dfs(int node,int par,vector<int>adj[],int &c,vector<int>&vis,int &f,int k){
        vis[node]=k;
        for(auto x:adj[node]){
            if(!vis[x]){
                if(dfs(x,node,adj,c,vis,f,k)){
                    if(f!=-1){
                        c++;   
                    }
                    if(f==node){
                        f=-1;
                    }
                    return true;
                }
            }else if(vis[x]==k) {
                c++;
                f=x;
                return true;
            }
        }
        return false;
    }
    int longestCycle(vector<int>& ed) {
        int n=ed.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            if(ed[i]!=-1)
                adj[i].push_back(ed[i]);
        }
        vector<int>vis(n,0);
        int ans=-1,k=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                k++;
                int c=0,f=0;
                if(dfs(i,-1,adj,c,vis,f,k)){
                    //cout<<"debug"<<c;
                    ans=max(ans,c);   
                }
            }
        }
        return ans;
    }
};