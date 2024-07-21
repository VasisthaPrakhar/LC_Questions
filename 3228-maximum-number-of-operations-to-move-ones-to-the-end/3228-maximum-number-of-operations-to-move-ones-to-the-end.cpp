class Solution {
public:
    int maxOperations(string s) {
        int n=s.length(),ans=0,c=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                while(i<n && s[i]=='0'){
                    i++;
                }
                i--;
                ans+=c;
            }else{
                c++;
            }
        }
        return ans;
    }
};