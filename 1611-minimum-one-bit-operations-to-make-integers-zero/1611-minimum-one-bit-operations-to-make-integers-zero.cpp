class Solution {
public:
    typedef long long int ll;
    int minimumOneBitOperations(int n) {
        if(n==0){
            return 0;
        }
        vector<ll>dp(32,0);
        dp[0]=1;
        dp[1]=3;
        for(int i=2;i<32;i++){
            dp[i]=2*dp[i-1]+1;
        }
        vector<int>a;
        int num=n;
        while(num){
            a.push_back(num%2);
            num/=2;
        }
        int m=a.size();
        ll ans=dp[m-1],k=0;
        //cout<<ans<<" "<<m;
        for(int i=0;i<m-1;i++){
            if(a[i]>0){
                k=dp[i]-k;
            }
        }
        return ans-k;
    };
};