class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.length();
        for(int l=1;l<=n/2;l++){
            int k=0,flag=0;
            string temp=s.substr(k,l);
            k+=l;
            while(k<n){
                string temp1=s.substr(k,l);
                if(temp!=temp1){
                    flag=1;
                    break;
                }
                k+=l;
            }
            if(flag==0){
                return true;
            }
        }
        return false;        
    }
};