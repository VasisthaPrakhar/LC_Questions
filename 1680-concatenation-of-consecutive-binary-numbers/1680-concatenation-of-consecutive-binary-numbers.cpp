class Solution {
public:
    int bi(int n){
        int s=0;
        while(n){
            s++;
            n/=2;
        }
        return s;
    }
    int mod=1e9 + 7;
    int concatenatedBinary(int n) {
       long long int ans=0;
       for(int i=1;i<=n;i++){
           ans = ((ans<<bi(i))%mod + i)%mod;
       }
        return ans%mod;
    }
};