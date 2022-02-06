#define mod 1000000007
class Solution {
public:
    int dp(int idx,int prev,map<int,map<int,int>> &memo,int &n){
        if(idx==n){
            return 1;
        }
        if(!memo.count(idx) || !memo[idx].count(prev)){
            int ans=0;
            if(idx==0){
                for(int i=0;i<5;i++){
                    ans=(ans+dp(idx+1,i,memo,n)%mod)%mod;
                }
            }else{
                if(prev==0){
                    ans=(ans+dp(idx+1,1,memo,n)%mod)%mod;
                }else if(prev==1){
                    ans=(ans+dp(idx+1,0,memo,n)%mod)%mod;
                    ans=(ans+dp(idx+1,2,memo,n)%mod)%mod;
                }else if(prev==2){
                    for(int i=0;i<5;i++){
                        if(i!=2){
                            ans=(ans+dp(idx+1,i,memo,n)%mod)%mod;
                        }
                    }
                }
                else if(prev==3){
                    ans=(ans+dp(idx+1,2,memo,n)%mod)%mod;
                    ans=(ans+dp(idx+1,4,memo,n)%mod)%mod;
                }else{
                    ans=(ans+dp(idx+1,0,memo,n)%mod)%mod;
                }
            }
            memo[idx][prev]=ans;
        }
        return memo[idx][prev];
    }
    int countVowelPermutation(int n) {
         map<int,map<int,int>>memo;
        return dp(0,0,memo,n);
    }
};