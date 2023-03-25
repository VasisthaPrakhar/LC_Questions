class Solution {
public:
    void dfs(int node,vector<int>adj[],int &cnt,vector<int>&vis){
        vis[node]=1;
        cnt++;
        for(auto x:adj[node]){
            if(!vis[x]){
                dfs(x,adj,cnt,vis);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& ed) {
        vector<long long>a;
        long long ans=0,cnt=0,sum=0;
        vector<int>vis(n,0),adj[n];
        for(auto x:ed){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int cnt=0;
                dfs(i,adj,cnt,vis);
                a.push_back(cnt);
            }
        }
        // for(int i=0;i<a.size();i++){
        //     for(int j=i+1;j<a.size();j++){
        //         ans+=a[i]*a[j];
        //     }
        // }
        sort(a.rbegin() , a.rend());
        
        for (int i = 0 ; i < a.size() ; i++){
         
            sum += a[i];
            ans +=  a[i] * (n-sum);
            
        }
        return ans;
    }
};