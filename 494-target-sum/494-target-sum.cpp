class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int d) {
        int n=arr.size(),sum=0;
        // int s=0,w=0;
        // for(auto x:nums){
        //     s+=x;
        // }
        // if(s<abs(target) || (s+target)%2!=0){
        //     return 0;
        // }
        // w=(s+target)/2;
        // int dp[n+1][w+1];
        // memset(dp,0,sizeof(dp));
        // // for(int i=0;i<=n;i++){
        // //     dp[i][0]=1;
        // // }
        // dp[0][0]=1;
        // for(int i=1;i<=n;i++){
        //     for(int j=0;j<=w;j++){
        //         if(nums[i-1]<=j){
        //             dp[i][j]+=dp[i-1][j]+dp[i-1][j-nums[i-1]];
        //         }else{
        //             dp[i][j]=dp[i-1][j];
        //         }
        //     }
        // }
        // return dp[n][w];
        int mod=1000000007;
        for(int i=0;i<n;i++){
		sum+=arr[i];
	}
	if(abs(d)>sum || (sum+d)%2){
		return 0;
	}
	int w=(sum+d)/2;
// 	int dp[n+1][w+1];

	vector<vector<int>>dp(n+1,vector<int>(w+1,0));
	for(int i=0;i<=w;i++){
		dp[0][i]=0;
	}
	for(int i=0;i<=n;i++){
		dp[i][0]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=w;j++){
			if(j>=arr[i-1]){
				dp[i][j]=(dp[i-1][j]+dp[i-1][j-arr[i-1]])%mod;
			}else{
				dp[i][j]=dp[i-1][j]%mod;
			}
		}
	}
	return dp[n][w];
    }
};
