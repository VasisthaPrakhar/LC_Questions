class Solution {
public:
    int largestVariance(string s) {
        int n=s.length(),ans=0;
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                if(i!=j){
                    int h=0,l=0,f=0;
                    for(int k=0;k<n;k++){
                        if(s[k]-'a'==i){
                            h++;
                        }
                        if(s[k]-'a'==j){
                            l++;
                        }
                        if(l>0){
                            ans=max(ans,h-l);
                        }else{
                            //cout<<h<<endl;
                            if(f){ans=max(ans,h-1);}
                        }
                        if(l>h){
                            f=1;
                            h=0,l=0;
                            //k--;
                        }
                    }
                }
            }
        }
        return ans;
    }
};