class Solution {
public:
    string breakPalindrome(string p) {
        if(p.length()==0 || p.length()==1){
            return "";
        }
        string p1=p;
        int flag=0,cnta=0;
        for(auto x:p){
            if(x=='a')
            cnta++;
            }
        for(auto &x:p1){
            if(x=='a'){
                continue;
            }
            else{
                x='a';
                flag=1;
                break;
            }
        }
        
        if(p.length()%2!=0 && p[p.length()/2]!='a' && cnta==p.length()-1){
            p[p.length()-1]='b';
            return p;
        }
        if(flag==0){
            p1[p1.length()-1]='b';
        }
        return p1;
    }
};