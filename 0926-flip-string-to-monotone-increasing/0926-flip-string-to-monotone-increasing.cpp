class Solution {
public:
    int minFlipsMonoIncr(string &s) {
        int c0=0,c1=0,n=s.length(),ans=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                if(c1>0){
                    c0++;
                    ans=min(c1,c0);
                }
            }else{
                c1++;
                if(ans!=-1){
                    c0=ans;
                }
            }
        }
        return ans==-1?0:ans;
    }
};