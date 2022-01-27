class Solution {
public:
    int minimumSwap(string s1, string s2) {
        if(s1==s2){
            return 0;
        }
        int n=s1.size();
        int m=s2.size();
        int cx=0,cy=0;
        for(int i=0;i<n;i++){
            if(s1[i]=='x'){
                cx++;
            }else{
                cy++;
            }
        }
        for(int i=0;i<m;i++){
            if(s2[i]=='x'){
                cx++;
            }else{
                cy++;
            }
        }
       // cout<<cx<<" "<<cy;
        if(cx%2==0 && cy%2==0){
            int difx=0,dify=0,ans=0;
            for(int i=0;i<n;i++){
                if(s1[i]!=s2[i]){
                    if(s1[i]=='x'){
                        difx++;
                    }else{
                        dify++;
                    }
                }
            }
            if(difx%2){
                ans+=difx/2 +1;
            }else{
                ans+=difx/2;
            }
            if(dify%2){
                ans+=dify/2 +1;
            }else{
                ans+=dify/2;
            }
            return ans;
        }
        return -1;
    }
};