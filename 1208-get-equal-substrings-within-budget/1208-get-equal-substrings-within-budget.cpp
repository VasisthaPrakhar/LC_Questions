class Solution {
public:
    int equalSubstring(string s, string t, int mc) {
        int n=s.length();
        int i=0,j=0,ans=0;
        while(j<n){
            mc=mc-abs(s[j]-t[j]);
            while(i<=j && mc<0){
                mc+=abs(s[i]-t[i]);
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};