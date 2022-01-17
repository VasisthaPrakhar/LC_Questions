class Solution {
public:
    char fun(char a,char b){
        int temp=b-'0';
        return char(a+temp);
    }
    string replaceDigits(string s) {
        for(int i=1;i<s.length();i=i+2){
            s[i]=fun(s[i-1],s[i]);
        }
        return s;
    }
};