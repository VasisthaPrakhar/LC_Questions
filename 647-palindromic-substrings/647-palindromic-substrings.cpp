class Solution {
public:
    bool fun(string &s,int i,int j){
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++,j--;
        }
        return true;
    }
    int countSubstrings(string s) {
        int n=s.length();
        if(n==1){
            return 1;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(fun(s,i,j)){
                    ans++;
                }
            }
        }
        return ans+n;
    }
};