class Solution {
public:
    string maximumBinaryString(string b) {
        int n=b.length();
        int idx=0,c0=0,c01=0,f=0;
        for(int i=0;i<n;i++){
            if(b[i]=='0'){
                if(f==0){
                    idx=i;
                    f++;
                }
                c0++;
            }else{
                if(f>0){
                    c01++;
                }
            }
        }
        if(c0==0||c0==1){
            return b;
        }
        string ans="";
        for(int i=0;i<idx;i++){
            ans=ans+b[i];
        }
            int k=c0-1;
            while(k--){
                ans.push_back('1');
            }
            ans.push_back('0');
        while(c01--){
            ans.push_back('1');
        }
        return ans;
    }
};