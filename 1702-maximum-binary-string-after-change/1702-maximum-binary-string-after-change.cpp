class Solution {
public:
    string maximumBinaryString(string binary) {
        int n=binary.length();
        string ans;
        int c0=0,f=0,idx=0;
        for(int i=0;i<n;i++){
            if(binary[i]=='0'){
                if(f==0){
                    idx=i;
                    f++;
                }
                c0++;
            }
            ans+="1";
        }
        if(c0==0 || c0==1){
            return binary;
        }
        ans[idx+c0-1]='0';
        return ans;
    }
};