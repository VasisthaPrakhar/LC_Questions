class Solution {
public:
    typedef long long int ll;
    long long maximumImportance(int n, vector<vector<int>>& r) {
        // int m=r.size();
        // unordered_map<int,int>mp;
        // for(int i=0;i<m;i++){
        //     mp[r[i][0]]++;
        //     mp[r[i][1]]++;
        // }
        // priority_queue<pair<int,int>>pq;
        // for(int i=0;i<n;i++){
        //     pq.push({mp[i],i});
        // }
        // int k=n;
        // vector<int>a(n);
        // while(!pq.empty()){
        //     int x=pq.top().second;
        //     a[x]=k--;
        //     pq.pop();
        // }
        // ll ans=0;
        // for(int i=0;i<m;i++){
        //     ans+=a[r[i][0]]+a[r[i][1]];
        // }
        // return ans;
        vector<int>adj[n],a(n);
        vector<pair<int,int>>ind(n);
        for(auto &x:r){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        for(int i=0;i<n;i++){
            ind[i].first=adj[i].size();
            ind[i].second=i;
        }
        sort(ind.begin(),ind.end(),[](pair<int,int>&a,pair<int,int>&b)->bool{
            if(a.first==b.first){
                return a.second>b.second;
            }
            return a.first>b.first;
        });
        int k=n;
        long long int ans=0;
        for(auto &x:ind){
            a[x.second]=k--;
        }
        for(auto &x:r){
            ans+=a[x[0]]+a[x[1]];
        }
        return ans;
    }
};