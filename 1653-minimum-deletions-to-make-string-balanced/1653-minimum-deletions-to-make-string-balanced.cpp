class Solution {
public:
    int minimumDeletions(string &s) {
        int n=s.length();
        vector<int>suf(n,0),pre(n,0);
        for(int i=0;i<n;i++){
            if(i==0){
                if(s[i]=='b'){
                    pre[i]=1;
                }
            }else{
                pre[i]=pre[i-1]+(s[i]=='b');
            }
        }
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                if(s[i]=='a'){
                    suf[i]=1;
                }
            }else{
                suf[i]=suf[i+1]+(s[i]=='a');
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans,pre[i]+suf[i]-1);
        }
        return ans;
    }
};