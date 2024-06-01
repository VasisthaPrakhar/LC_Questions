class Solution {
public:
    int scoreOfString(string s) {
        int ans=0,n=s.length();
        for(int i=0;i<n-1;i++){ans+=abs(s[i]-s[i+1]);}
        return ans;
    }
};