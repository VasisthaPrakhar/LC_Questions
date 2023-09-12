class Solution {
public:
    bool fun(string &s){
        int i=0,j=s.length()-1;
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++,j--;
        }
        return true;
    }
    bool isPalindrome(string s) {
        string t="";
        for(auto x:s){
            if(isalpha(x)){
                t.push_back(tolower(x));
            }
            if(isdigit(x)){
                t.push_back(x);
            }
        }
        return fun(t);
    }
};