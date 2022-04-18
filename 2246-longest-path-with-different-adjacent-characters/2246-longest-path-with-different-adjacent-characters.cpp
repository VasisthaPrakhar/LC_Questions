class Solution {
public:
    int ans=0;
    int fun(vector<int>adj[],string &s,int root){
        vector<int>a;
        for(auto x:adj[root]){
            if(s[root]==s[x]){
                ans=max(ans,fun(adj,s,x));
            }else{
                a.push_back(1+fun(adj,s,x));
            }
        }
        sort(a.rbegin(),a.rend());
        if(!a.size()){
            return 0;
        }
        if(a.size()>1){
            ans=max(ans,a[0]+a[1]);
        }
        return a[0];        
    }
    int longestPath(vector<int>& par, string s) {
        int n=par.size();
        vector<int>adj[n];
        for(int i=1;i<n;i++){
            adj[par[i]].push_back(i);
        }
        ans=max(ans,fun(adj,s,0));
        return ans+1;
    }
};