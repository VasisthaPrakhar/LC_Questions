static auto fast_io = [] { ios::sync_with_stdio(false); cout.tie(nullptr); cin.tie(nullptr); return 0; }();
class Solution {
public:
    typedef long long int ll;
    int fun1(int node, ll sum,vector<pair<int,int>>adj[], int sp ,unordered_set<int>&vis){
        vis.insert(node);
        int res=0;
        if(sum%sp==0){
            res++;
        }
        for(auto x:adj[node]){
            if(vis.find(x.first)==vis.end()){
                res+=fun1(x.first,sum+x.second,adj,sp,vis);
            }
        }
        return res;
    }
    int fun(int root,vector<pair<int,int>>adj[],int sp){
        vector<int>a;
        for(auto x:adj[root]){
            unordered_set<int>vis;
            vis.insert(root);
            a.push_back(fun1(x.first,x.second,adj,sp,vis));
        }
        if(a.size()<2){return 0;}
        int ans=0;
        for(int i=0;i<a.size()-1;i++){
            if(a[i]==0){continue;}
            for(int j=i+1;j<a.size();j++){
                if(a[j]!=0)
                    ans+=(ll)a[i]*(ll)a[j];
            }
        }
        return ans;
    }
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& ed, int sp) {
        int n=ed.size();
        vector<pair<int,int>>adj[n+1];
        for(auto x:ed){
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }
        vector<int>ans;
        for(int i=0;i<n+1;i++){
            int res=fun(i,adj,sp);
           //cout<<endl;
            ans.push_back(res);
        }
        return ans;
    }
};