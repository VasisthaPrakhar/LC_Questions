class Solution {
public:
    bool check(string s, int i){
        s[i]='a';
        string s1=string(s.rbegin(),s.rend());
        if(s1==s){
            return true;
        }
        else{
            return false;
        }
    }
    string breakPalindrome(string p) {
        if(p.length()==1){
            return "";
        }
        int i=0,f=1;
        while(i<p.length()){
            if(p[i]=='a'){
                i++;
            }
            else if(check(p,i)){
                i++;
            }
            else{
                f=0;
                p[i]='a';
                break;
            }
        }
        if(f==0){
            return p;
        }
        else{
            p[p.length()-1] += 1;
            return p;
        }
    }
};