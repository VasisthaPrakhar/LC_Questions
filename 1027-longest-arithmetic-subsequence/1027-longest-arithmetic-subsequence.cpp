class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        //unordered_map<int,unordered_map<int,int>>mp;
        vector<vector<int>>dp(2001,vector<int>(2001,0));
        int n=nums.size();
        int ans=2;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int d=nums[j]-nums[i]+1000;
                // mp[j][d]=2;
                // if(mp.count(i)){
                //     if(mp[i].count(d)){
                //         mp[j][d]=max(2,mp[i][d]+1);
                //     }
                // }
                dp[j][d]=max(dp[i][d]+1,2);
                ans=max(ans,dp[j][d]);
            }
        }
        return ans;
    }
};
static auto fast_io = [] { ios::sync_with_stdio(false); cout.tie(nullptr); 
                          cin.tie(nullptr); return 0; }();
