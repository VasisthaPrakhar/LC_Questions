class Solution {
public:
    vector<int> bfs(vector<int>adj[],vector<int>adj1[],int n){
        vector<int>a(n,-1);
        int ans=0,f=0;
        queue<int>q;
        set<pair<int,int>>s;
        s.insert({0,0});
        q.push(0);
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int node=q.front();
                if(a[node]==-1)
                    a[node]=ans;
                q.pop();
                if(f%2){
                    for(auto x:adj1[node]){
                        if(s.find({1,x})==s.end()){
                            q.push(x);
                            s.insert({1,x});
                        }
                    }
                }else{
                    for(auto x:adj[node]){
                        if(s.find({0,x})==s.end()){
                            q.push(x);
                            s.insert({0,x});
                        }
                    }
                }
            }
            f++;
            ans++;
        }
        return a;
    }
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& re, vector<vector<int>>& be) {
        vector<int>adj[n],adj1[n];
        for(auto x:re){
            adj[x[0]].push_back(x[1]);
        }
        for(auto x:be){
            adj1[x[0]].push_back(x[1]);
        }
        vector<int>a=bfs(adj,adj1,n);
       
        vector<int>b=bfs(adj1,adj,n);
        //  for(auto x:a){
        //     cout<<x<<endl;
        // }
        for(int i=0;i<n;i++){
            if(a[i]!=-1 && b[i]!=-1){
                a[i]=min(a[i],b[i]);
            }else{
                a[i]=max(a[i],b[i]);
            }
        }
        return a;
    }
};