class Solution {
public:
    string longestPalindrome(string s) {
       int n=s.length(),ma=0,left;
        for(int i=0;i<n;i++){
            int r=i;
            while(r<n && s[i]==s[r]){
                r++;
            }
            int l=i-1;
            while(l>=0 && r<n && s[l]==s[r]){
                l--;
                r++;
            }
            r--,l++;
            if(ma<r-l+1){
                ma=r-l+1;
                left=l;
            }
        }
        return s.substr(left,ma);
    }
};