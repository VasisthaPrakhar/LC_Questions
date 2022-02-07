#define mod 1000000007
class Solution {
public:
    int dp(vector<vector<long long int>>&memo,int n, int &k, int t){
        if(t<=0 || n<=0){
            return (t!=0||n!=0)?0:1;
        }
        if(memo[t][n]==-1){
            long long int res=0;
            for(int i=1;i<=k;i++){
                res=(res%mod + (dp(memo,n-1,k,t-i))%mod)%mod;
            }
            memo[t][n]=res%mod;
        }
        return memo[t][n];
    }
    int numRollsToTarget(int n, int k, int target) {
        if(n*k<target){
            return 0;
        }
        vector<vector<long long int>>memo(target+1,vector<long long int>(n+1,-1));
        return dp(memo,n,k,target);
    }
};