class Solution {
public:
    int memo[10001][7][7];
    int mod=1000000007;
    int fun(int n,int prev,int prevprev){
        if(n==0){
            return 1;
        }
        if(memo[n][prev][prevprev]==-1){
            int res=0;
            for(int i=1;i<=6;i++){
                if(i!=prev && i!=prevprev && (prev==0 || __gcd(prev,i)==1)){
                    res=(res%mod + fun(n-1,i,prev)%mod)%mod;
                }
            }
            memo[n][prev][prevprev]=res;
        }
        return memo[n][prev][prevprev];
    }
    int distinctSequences(int n) {
        memset(memo,-1,sizeof(memo));
        return fun(n,0,0);
    }
};