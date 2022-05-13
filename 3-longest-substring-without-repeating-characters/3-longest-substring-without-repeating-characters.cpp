class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        unordered_map<char,int>m;
        int i=0,j=0,ans=0;
        while(j<n){
            m[s[j]]++;
            while(i<=j && m[s[j]]>1){
                m[s[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};