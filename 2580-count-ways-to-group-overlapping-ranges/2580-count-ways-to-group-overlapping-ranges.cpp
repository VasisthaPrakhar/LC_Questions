class Solution {
public:
    typedef long long int ll;
    int mod=1e9 + 7;
    int countWays(vector<vector<int>>& r) {
        sort(r.begin(),r.end());
        int end=r[0][1];
        ll n=r.size(),cnt=1;
        for(int i=1;i<n;i++){
            if(r[i][0]<=end){
                end=max(r[i][1],end);
            }else{
                cnt++;
                end=r[i][1];
            }
        }
        ll ans=1;
        for(int i=1;i<=cnt;i++){
            ans=(ans*2)%mod;
        }
        return ans;
    }
};