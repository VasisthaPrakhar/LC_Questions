class Solution {
public:
    int longestSubstring(string s, int k) {
        unordered_map<char,int>m;
        int n=s.length();
        if(k>n){
            return 0;
        }
        int ans=0,i=0,j=0;
        while(j<n){
            m[s[j]]++;
            j++;
        }
        while(i<n && m[s[i]]>=k){
            i++;
        }
        if(i==n){
            return n;
        }
        int l=longestSubstring(s.substr(0,i),k);
        int r=longestSubstring(s.substr(i+1),k);
        ans=max(l,r);
        return ans;
    }
};