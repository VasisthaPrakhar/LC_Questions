class Solution {
public:
    int fun(int root,vector<int>adj[],int &ans,int par){
        set<int>s;
        int res=0;
        for(auto x:adj[root]){
            if(x==par){
                //cout<<x<<" "<<par<<" "<<root<<endl;
                continue;
            }
            int k=fun(x,adj,ans,root);
            res+=k;
            s.insert(k);
        }
        if(s.size()<=1){
            ans++;
        }
        return res+1;
    }
    int countGoodNodes(vector<vector<int>>& ed) {
        int n=ed.size() +1;
        vector<int>adj[n];
        for(auto x:ed){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        int ans=0;
        fun(0,adj,ans,-1);
        return ans;
    }
};