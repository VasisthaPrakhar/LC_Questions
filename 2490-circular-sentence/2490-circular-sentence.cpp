class Solution {
public:
    bool isCircularSentence(string &s) {
        int n=s.length();
        char a=s[0];
        for(int i=0;i<n;i++){
            if(i==n-1){
                if(a!=s[i]){
                    return false;
                }
            }else{
                if(s[i]==' '){
                    if(s[i-1]!=s[i+1]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};