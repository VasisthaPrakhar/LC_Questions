class Solution {
public:
    typedef long long int ll;
    long long maximumImportance(int n, vector<vector<int>>& r) {
        int m=r.size();
        unordered_map<int,int>mp;
        for(int i=0;i<m;i++){
            mp[r[i][0]]++;
            mp[r[i][1]]++;
        }
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++){
            pq.push({mp[i],i});
        }
        int k=n;
        vector<int>a(n);
        while(!pq.empty()){
            int x=pq.top().second;
            a[x]=k--;
            pq.pop();
        }
        ll ans=0;
        for(int i=0;i<m;i++){
            ans+=a[r[i][0]]+a[r[i][1]];
        }
        return ans;
    }
};