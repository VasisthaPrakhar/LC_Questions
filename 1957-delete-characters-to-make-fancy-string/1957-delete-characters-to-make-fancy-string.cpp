class Solution {
public:
    string makeFancyString(string &s) {
        int n=s.length();
        if(n<3){
            return s;
        }
        for(int i=0;i<n-2;i++){
            if(s[i] != '@' && s[i]==s[i+1] && s[i+1]==s[i+2]){
                s[i]='@';
            }
        }
        string t="";
        for(int i=0;i<n;i++){
            if(s[i]!='@'){
                t.push_back(s[i]);
            }
        }
        return t;
    }
};