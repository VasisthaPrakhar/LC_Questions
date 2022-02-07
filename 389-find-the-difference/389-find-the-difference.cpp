class Solution {
public:
    char findTheDifference(string s, string t) {
        int n=s.length();
        int a[26]={0};
        for(int i=0;i<n;i++){
            a[s[i]-'a']+=1;
        }
        char ans;
        for(int i=0;i<=n;i++){
            a[t[i]-'a']-=1;
            if(a[t[i]-'a']<0){
                ans=t[i];
                break;
            }
        }
        return ans;
    }
};