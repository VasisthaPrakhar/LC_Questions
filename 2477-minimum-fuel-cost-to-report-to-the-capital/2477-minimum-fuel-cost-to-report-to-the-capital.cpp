class Solution {
public:
    typedef long long int ll;
    ll ans=0;
    ll fun(int node,int st,vector<int>&vis,vector<int>adj[]){
        vis[node]=1;
        ll res=1;
        for(auto x:adj[node]){
            if(!vis[x]){
                res+=fun(x,st,vis,adj);
            }
        }
        if(node!=0)
            ans+=(res+((ll)st-1LL))/(ll)st;
        //cout<<node<<" "<<res<<endl;
        return res;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int st) {
        int n=roads.size()+1;
        vector<int>adj[n];
        for(auto x:roads){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int>vis(n,0);
        ll ans1=fun(0,st,vis,adj);
        return ans;
    }
};