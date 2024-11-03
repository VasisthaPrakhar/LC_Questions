class Solution {
public:
    bool isBalanced(string &s) {
        int n=s.length(),a=0,b=0;
        for(int i=0;i<n;i++){
            if(i%2){
                b+=s[i]-'0';
            }else{
                a+=s[i]-'0';
            }
        }
        return a==b;
    }
};