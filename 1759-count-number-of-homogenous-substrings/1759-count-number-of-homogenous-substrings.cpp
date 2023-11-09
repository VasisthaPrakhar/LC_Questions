class Solution {
public:
    int mod=1e9+7;
    typedef long long int ll;
    int countHomogenous(string s) {
        int n=s.length();
        ll j=0,ans=0;
        while(j<n){
            ll k=1;
            j++;
            while(j<n && s[j]==s[j-1]){
                k++,j++;
            }
            j--;
            ans=(ans%mod + ((k*(k+1))/2)%mod)%mod;
            j++;
        }
        return ans;
    }
};