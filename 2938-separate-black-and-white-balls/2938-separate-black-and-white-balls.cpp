class Solution {
public:
    typedef long long int ll;
    long long minimumSteps(string s) {
        int n=s.length();
        int i=0,j=0;
        ll ans=0;
        while(j<n){
            if(s[j]=='0'){
                ans+=j-i;
                i++;
            }
            j++;
        }
        return ans;
    }
};