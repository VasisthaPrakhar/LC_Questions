class Solution {
public:
    int removePalindromeSub(string s) {
        int n=s.length();
        int j=n-1,i=0;
        while(i<=j){
            if(s[i]!=s[j]){
                return 2;
            }
            i++;
            j--;
        }
        return 1;
    }
};