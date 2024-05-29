class Solution {
public:
    int numSteps(string s) {
        int n=s.length();
        if(n==1){
            return 0;
        }
        if(s[n-1]=='1'){
            for(int j=n-1;j>=0;j--){
                if(s[j]=='0'){
                    s[j]='1';
                    break;
                }else{
                    s[j]='0';
                }
            }
            if(s[0]=='0'){
                s="1"+s;
            }
        }else{
            s.pop_back();
        }
        return 1 + numSteps(s);
    }
};