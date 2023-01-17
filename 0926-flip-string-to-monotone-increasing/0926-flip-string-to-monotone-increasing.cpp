class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int c0=0,c1=0,n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                c0++;
            }else{
                c1++;
            }
            c0=min(c0,c1);
        }
        return c0;
    }
};