class Solution {
public:
    bool check(string &s,int i,int j){
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++,j--;
        }
        return true;
    }
    int fun(string &s, int i,int j,vector<int>&dp){
        if(i>=j){
            return 0;
        }
        if(check(s,i,j)){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int res=2500;
        for(int z=i;z<=j;z++){
            if(check(s,i,z)){
                res=min(res,fun(s,z+1,j,dp)+1);
            }
            // cout<<res<<" ";
        }
        
        return dp[i]=res;
    }
    int minCut(string s) {
        int n=s.length();
        vector<int>dp(n+1,-1);
        // for(int i=0;i<=n;i++){
        //     for(int j=0;j<=n;j++){
        //         if(i>=j || i==n || j==n){
        //             dp[i][j]=0;
        //         }      
        //     }
        // }
        // for(int i=0;i<n;i++){
        //         // if(i>=j){
        //         //     break;
        //         // }
        //     if(check(s,i,j)){
        //         dp[i][j]=0;
        //     }
        //     for(int k=i;k<=j;k++){
        //         if(check(s,i,k)){
        //             dp[i][j]=min(dp[i][j],dp[k+1][j]+1);    
        //         }
        //     }
        // }
        // for(auto x:dp){
        //     for(auto y:x){
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }
        return fun(s,0,n-1,dp);
    }
};