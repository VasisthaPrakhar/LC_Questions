class Solution {
public:
    vector<int> fun(vector<int>adj[],int n,int src){
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        queue<int>q;
        q.push(src);
        while(!q.empty()){
            auto node=q.front();
            q.pop();
             for(auto x:adj[node]){
                if(dist[x]>dist[node]+1){
                    dist[x]=dist[node]+1;
                    q.push(x);
                }
            }
        }
        return dist;
    }
    int closestMeetingNode(vector<int>& ed, int n1, int n2) {
        int n=ed.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            if(ed[i]!=-1)
                adj[i].push_back(ed[i]);
        }
        vector<int>a=fun(adj,n,n1);
        vector<int>b=fun(adj,n,n2);
        int ans=INT_MAX,res=-1;
        for(int i=0;i<n;i++){
            int t=max(a[i],b[i]);
            if(ans>t){
                ans=t;
                res=i;
            }
        }        
        return res;
    }
};