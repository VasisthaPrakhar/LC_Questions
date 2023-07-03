class Solution {
public:
    bool buddyStrings(string s, string t) {
        int n=s.length();
        int m=t.length(),f=0;
        if(n!=m){return false;}
        char a,b;
        unordered_set<char>st;
        for(int i=0;i<n;i++){
            if(!f){
                if(s[i]!=t[i]){
                    a=s[i];
                    b=t[i];
                    f++;
                }
            }else{
                if(s[i]!=t[i]){
                    if(a!=t[i] || b!=s[i]){
                        return false;
                    }
                    f++;
                }
            }
            st.insert(s[i]);
        }
        if((s==t && st.size()<n)||f==2){
            return true;
        }
        return false;
    }
};