class Solution {
public:
    typedef long long int ll;
    long long maximumImportance(int n, vector<vector<int>>& r) {
        int m=r.size();
        vector<int>mp(n,0);
        for(int i=0;i<m;i++){
            mp[r[i][0]]++;
            mp[r[i][1]]++;
        }
        sort(mp.begin(),mp.end());
        ll ans=0;
        for(int i=0;i<n;i++){
            ans+=(ll)mp[i]*(ll)(i+1);
        }
        return ans;
    }
};