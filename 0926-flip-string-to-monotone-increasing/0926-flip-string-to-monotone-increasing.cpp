class Solution {
public:
    int minFlipsMonoIncr(string &s) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int c0=0,c1=0,n=s.length(),ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                if(c1>0){
                    c0++;
                    ans=c1>c0?c0:c1;
                }
            }else{
                c1++;
                if(c0>0){
                    c0=ans;
                }
            }
        }
        return ans;
    }
};