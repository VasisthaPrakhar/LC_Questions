class Solution {
public:
    int lastStoneWeightII(vector<int>& a) {
        int n=a.size(),w,sum=0;
        for(int i=0;i<n;i++){
            sum+=a[i];
        }
        w=sum/2;
        bool dp[n+1][w+1];
        for(int i=0;i<=w;i++){
            dp[0][i]=false;
        }
        for(int i=0;i<=n;i++){
            dp[i][0]=true;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=w;j++){
                if(j>=a[i-1]){
                    dp[i][j]=dp[i-1][j]||dp[i-1][j-a[i-1]];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<=w;i++){
            if(dp[n][i]){
                ans=min(ans,sum-2*i);
            }
        }
        return ans;
    }
};