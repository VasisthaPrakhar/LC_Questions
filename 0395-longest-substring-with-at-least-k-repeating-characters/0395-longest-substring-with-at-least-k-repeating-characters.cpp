class Solution {
public:
    int longestSubstring(string s, int k) {
        int n=s.length();
        if(k>n){
            return 0;
        }
        unordered_map<char,int>m;
        int ans=0,i=0;
        for(int i=0;i<n;i++){
            m[s[i]]++;
        }
        while(i<n && m[s[i]]>=k){
            i++;
        }
        if(i==n){
            return n;
        }
        int l=longestSubstring(s.substr(0,i),k);
        while(i<n && m[s[i]]<k) 
            i++;
        int r=longestSubstring(s.substr(i),k);
        ans=max(l,r);
        return ans;
    }
};