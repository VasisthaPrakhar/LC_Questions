class Solution {
public:
    int minOperations(string s) {
        int n=s.length(),c1o=0,c0o=0,c1e=0,c0e=0;
        for(int i=0;i<n;i++){
            if(i%2){
                if(s[i]=='1'){
                    c1o++;
                }else{
                    c0o++;
                }
            }else{
                if(s[i]=='1'){
                    c1e++;
                }else{
                    c0e++;
                }
            }
        }
        return min((c1e+c0o),(c1o+c0e));
    }
};