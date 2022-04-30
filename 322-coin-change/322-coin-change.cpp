class Solution {
public:
    // int dp(vector<int>& co,int am,unordered_map<int,int> &memo,int &n){
    //     if(am==0){
    //         return 0;
    //     }
    //     if(!memo.count(am)){
    //         int mi=INT_MAX;
    //         for(int i=0;i<n;i++){
    //             if(am-co[i]>=0){
    //                 mi=min((long long)mi,(long long)1+dp(co,am-co[i],memo,n));   
    //             }
    //         }
    //         memo[am]=mi;
    //     }
    //     return memo[am];
    // }
    int coinChange(vector<int>& co, int am) {
        if(am==0){
            return 0;
        }
        int n=co.size();
        int dp[n+1][am+1];
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<=am;i++){
            dp[0][i]=INT_MAX-1;
        }
        for(int i=1;i<=am;i++){
            if(i%co[0])
                dp[1][i]=INT_MAX-1;
            else
                dp[1][i]=i/co[0];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=am;j++){
                if(co[i-1]<=j){
                    dp[i][j]=min(dp[i-1][j],1+dp[i][j-co[i-1]]);
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        // unordered_map<int,int>memo;
        // for(auto x:co){
        //     if(x<=am){
        //         memo[x]=1;
        //     }
        // }
        // int ans=dp(co,am,memo,n);
        // return ans==INT_MAX?-1:ans;
        return dp[n][am]!=INT_MAX-1?dp[n][am]:-1;
    }
};