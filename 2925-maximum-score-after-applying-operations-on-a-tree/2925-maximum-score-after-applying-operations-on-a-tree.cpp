class Solution {
public:
    typedef long long int ll;
    // map<int,map<vector<int>,ll>>dp;
    // void fun(int node, vector<int>adj[],vector<int>&res,map<int,vector<int>>&m,vector<int>&vis){
    //     vis[node]=1;
    //     res.push_back(node);
    //     int f=0;
    //     for(auto x:adj[node]){
    //         if(!vis[x]){
    //             f=1;
    //             fun(x,adj,res,m,vis);
    //         }
    //     }
    //     if(f==0){
    //         m[node]=res;
    //     }
    //     res.pop_back();
    // }
    // bool check(int idx,vector<int>&v,map<int,vector<int>>&m){
    //     for(auto x:m){
    //         ll ans=0;
    //         for(auto y:x.second){
    //             ans+=v[y];
    //         }
    //         if(ans==0){
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    // ll fun1(int idx,int n,vector<int>&v,map<int,vector<int>>&m){
    //     if(idx>=n){
    //         return 0;
    //     }
    //     if(dp.count(idx)){
    //         if(dp[idx].count(v)){
    //             return dp[idx][v];
    //         }
    //     }
    //     ll res=0,res1=0;
    //     int t=v[idx];
    //     v[idx]=0;
    //     if(check(idx,v,m)){  
    //         res=t+fun1(idx+1,n,v,m);
    //     }
    //     v[idx]=t;
    //     res1=fun1(idx+1,n,v,m);
    //     return dp[idx][v]=max(res,res1);
    // }
    ll fun(int node, vector<int>adj[],map<int,ll>&m,vector<int>&vis,vector<int>&v){
        vis[node]=1;
        ll res=0;
        for(auto x:adj[node]){
            if(!vis[x]){
                res+=fun(x,adj,m,vis,v);
            }
        }
        return m[node]=v[node]+res;
    }
    ll fun1(int node, vector<int>adj[],map<int,ll>&m,vector<int>&vis,vector<int>&v,vector<ll>&dp){
        if(dp[node]!=-1){
            return dp[node];
        }
        vis[node]=1;
        ll res=0;
        int f=0;
        for(auto x:adj[node]){
            if(!vis[x]){
                f=1;
                res+=fun1(x,adj,m,vis,v,dp);
            }
        }
        if(!f){return 0;}
        return dp[node]=max((ll)v[node]+res,m[node]-v[node]);
    }
    long long maximumScoreAfterOperations(vector<vector<int>>& ed, vector<int>& v) {
        int n=v.size();
        vector<int>adj[n],vis(n,0);
        for(auto x:ed){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<ll>dp(n,-1);
        map<int,ll>m;
        ll sum = fun(0,adj,m,vis,v);
        for(auto &x:vis){x=0;}
        return fun1(0,adj,m,vis,v,dp);
    }
};