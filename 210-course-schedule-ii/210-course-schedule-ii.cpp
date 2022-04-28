class Solution {
public:
    bool fun(vector<int>adj[],int node,vector<int>&vis,vector<int>&dfsvis,stack<int>&st){
        vis[node]=1;
        dfsvis[node]=1;
        for(auto x:adj[node]){
            if(!vis[x]){
                if(fun(adj,x,vis,dfsvis,st)){
                    return true;
                }
            }else if(dfsvis[x]){
                return true;
            }
        }
        dfsvis[node]=0;
        st.push(node);
        return false;
    }
    vector<int> fun1(int n, vector<vector<int>>& p){
        int m=p.size();
        vector<int>adj[n];
        for(int i=0;i<m;i++){
            adj[p[i][1]].push_back(p[i][0]);
        }
        stack<int>st;
        vector<int>ans;
        vector<int>vis(n,0),dfsvis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(fun(adj,i,vis,dfsvis,st)){
                    return ans;
                }
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        return fun1(n,p);
    }
};