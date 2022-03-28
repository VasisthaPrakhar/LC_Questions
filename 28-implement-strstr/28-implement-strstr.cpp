class Solution {
public:
    int strStr(string ha, string s) {
        int n=s.length();
        int m=ha.length();
        if(n==0 || ha==s){
            return 0;
        }
        if(m<n){
            return -1;
        }
        for(int i=0;i<=m-n;i++){
            string temp=ha.substr(i,n);
            if(temp==s){
                return i;
            }
        }
        return -1;
    }
};