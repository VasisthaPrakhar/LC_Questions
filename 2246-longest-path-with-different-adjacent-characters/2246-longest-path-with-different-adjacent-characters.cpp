class Solution {
public:
    int ans=0;
    int fun(vector<int>adj[],string &s,int root){
        priority_queue<int>a;
        for(auto x:adj[root]){
            if(s[root]==s[x]){
                ans=max(ans,fun(adj,s,x));
            }else{
                a.push(1+fun(adj,s,x));
            }
        }
        if(a.empty()){
            return 0;
        }
        int k=a.top();
        a.pop();
        if(a.size()>0){
            ans=max(ans,a.top()+k);
        }
        return k;        
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