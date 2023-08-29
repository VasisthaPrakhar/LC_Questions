class Solution {
public:
    int bestClosingTime(string &s) {
        int n=s.length();
        vector<int>pre,suf(n,0);
        int c=0,c1=0;
        for(int i=0;i<n;i++){
            pre.push_back(c);
            if(s[i]=='N'){
                c++;
            }
            if(s[n-i-1]=='Y'){
                c1++;
            }
            suf[n-i-1]=c1;
        }
        int ans=INT_MAX,idx=0;
        //cout<<pre[n-1]<<" "<<suf[0]<<endl;
        for(int i=0;i<n;i++){
            int k=suf[i]+pre[i];
            if(ans>k){
                ans=k;
                idx=i;
            }
        }
        if(ans>c){
            idx=n;
        }
        return idx;
    }
};