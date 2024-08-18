class Solution {
public:
    int nthUglyNumber(int n) {
        // vector<int>sub={2,3,5};
        // bool dp[4][50001];
        // memset(dp,false,sizeof(dp));
        // for(int i=0;i<=3;i++){
        //     dp[i][0]=true;
        //     dp[i][1]=true;
        // }
        // for(int i=1;i<=3;i++){
        //     for(int j=1;j<=50000;j++){
        //         if(j%sub[i-1]==0){
        //             dp[i][j]=dp[i-1][j] || dp[i][j/sub[i-1]];
        //         }else{
        //             dp[i][j]=dp[i-1][j];
        //         }
        //     }
        // }
        // int k=1;
        // // for(int i=1;i<=50000;i++){
        // //     cout<<i<<" "<<dp[3][i]<<" ";
        // //     if(dp[3][i]){
        // //         cout<<k;
        // //         k++;
        // //     }
        // //     cout<<endl;
        // // }
        // return 0;
        int dp[n];
        dp[0]=1;
        int i=0,j=0,k=0;
        for(int p=1;p<n;p++){
            dp[p]=min(dp[i]*2,min(dp[j]*3,dp[k]*5));
            if(dp[p]==dp[i]*2){
                i++;
            }
            if(dp[p]==dp[j]*3){
                j++;
            }
            if(dp[p]==dp[k]*5){
                k++;
            }
        }
        // for(int i=0;i<n;i++){
        //     cout<<dp[i]<<endl;
        // }
        return dp[n-1];
    }
};