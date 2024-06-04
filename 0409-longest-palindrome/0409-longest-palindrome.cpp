class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.length(),ans=0;
        map<char,int>m;
        for(int i=0;i<n;i++){
            m[s[i]]++;
            if(m[s[i]]==2){
                ans+=2;
                m.erase(s[i]);
            }
        }
        if(m.size()){
            ans++;
        }
        return ans;
    }
};