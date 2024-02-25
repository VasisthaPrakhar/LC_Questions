class Solution {
public:
    set<int> fun(int n){
        set<int>res;
        while(n%2==0){ 
            res.insert(2);
            n=n/2; 
        }
        for(int i=3;i<=sqrt(n);i=i+2){ 
            while(n % i == 0){
                res.insert(i);
                n = n/i; 
            }
        } 
        if (n > 2)
            res.insert(n);
        return res;
    }
    int findpar(int u,vector<int>&par){
        if(u==par[u])
            return u;
        return findpar(par[u],par);
    }
    void unionn(int u,int v,vector<int>&par,vector<int>&rank){
        u=findpar(u,par);
        v=findpar(v,par);
        if(rank[u]<rank[v]){
            par[u]=v;
        }        else if(rank[v]<rank[u]){
            par[v]=u;
        }else{
            par[v]=u;
            rank[u]++;
        }
    }
    bool canTraverseAllPairs(vector<int>& nums) {
        int n=nums.size();
        map<int,vector<int>>m;
        for(int i=0;i<n;i++){
            set<int>s=fun(nums[i]);
            //  for(auto y:s){
            //     cout<<y<<" ";
            // }
            // cout<<endl;
            for(auto x:s){
                m[x].push_back(i);
            }
        }
        // for(auto x:m){
        //     cout<<x.first<<": ";
        //     for(auto y:x.second){
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }
        vector<int>adj[n];
        for(auto x:m){
            int n1=x.second.size();
            for(int i=1;i<n1;i++){
                adj[x.second[i]].push_back(x.second[i-1]);
                adj[x.second[i-1]].push_back(x.second[i]);
            }
        }
        vector<int>par(n),rank(n,0);
        for(int i=0;i<n;i++){par[i]=i;}
        for(int i=0;i<n;i++){
            for(auto x:adj[i]){
                unionn(i,x,par,rank);
            }
        }
        for(int i=1;i<n;i++){
            if(findpar(0,par)!=findpar(i,par)){
                return false;
            }
        }
        return true;
    }
};