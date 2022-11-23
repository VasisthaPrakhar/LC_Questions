class Solution {
public:
    typedef long long int ll;
    int mod=1e9 +7;
    bool isprime(char ch){
        return ch=='2'||ch=='3'||ch=='5'||ch=='7';
    }
    int dp[1002][1002];
    int fun(string &s,int st,int k,int no,int mi,int n){
        if(no>k){
            return 0;
        }
        if(no==k){
            if(st<=n-mi)
                return 1;
            else
                return 0;
        }
        if(dp[st][no]!=-1){
            return dp[st][no];
        }
        ll res=0;
        for(int i=st+mi;i<=n-mi*((k-no)-1);i++){
            if(isprime(s[i]) && !isprime(s[i-1])){
                res = (res%mod + fun(s,i,k,no+1,mi,n)%mod)%mod;
            }
        }
        return dp[st][no]=res%mod;
    }
    int beautifulPartitions(string &s, int k, int mi) {
        int n=s.length();
        if(isprime(s[n-1]) || !isprime(s[0])){
            return 0;
        }
        if(mi>n/k){
            return 0;
        }
        if(k==1){
            return 1;
        }
        memset(dp,-1,sizeof(dp));
        return fun(s,0,k,1,mi,n);
    }
};
#pragma GCC optimize("fast")
static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();