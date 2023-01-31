class Solution {
public:
    int bestTeamScore(vector<int>& s, vector<int>& a) {
        int n=a.size();
        vector<int>dp(n,0);
        vector<pair<int,int>>v;
        int ans=0;
        for(int i=0;i<n;i++){
            v.push_back({a[i],s[i]});
        }
        sort(v.rbegin(),v.rend());
        for(int i=0;i<n;i++){
            int k=v[i].second;
            dp[i]=k;
            for(int j=0;j<i;j++){
                if(v[j].second>=v[i].second){
                    dp[i]=max(dp[i],dp[j]+k);
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};