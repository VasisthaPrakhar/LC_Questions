class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int n=s.length();
        int f=0,j=0,ans=0,res=0,no=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                no=i;
            }
        }
        if(no==-1){
            return 0;
        }
        no++;
        while(j<no){
            if(f && s[j]=='1' && s[j-1]=='1'){
                res++;
            }
            if(res && s[j]=='0' && s[j-1]=='0'){
                res--;
            }
            if(s[j]=='0'){
                f=1;
                ans++;
            }
            j++;
        }
        return ans+res;
    }
};