class Solution {
public:
    typedef long long int ll;
    int mod=1e9+7;
    int dp[2001][51][52];
    ll fun(int idx,int n,int p1,int p2,vector<int>&nums){
        if(idx>=n){
            return 1;
        }
        if(nums[idx]<p1){
            return 0;
        }
        if(dp[idx][p1][p2]!=-1){
            return dp[idx][p1][p2];
        }
        ll res=0;
        for(int i=p1;i<=nums[idx];i++){
            int j=nums[idx]-i;
            //cout<<i<<" "<<j<<" "<<idx<<endl;
            if(j<=p2){
                //cout<<i<<" "<<j<<" "<<idx<<endl;
                res+=fun(idx+1,n,i,j,nums);
            }
        }
        return dp[idx][p1][p2]=res%mod;
    }
    int countOfPairs(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return fun(0,n,0,51,nums);
    }
};