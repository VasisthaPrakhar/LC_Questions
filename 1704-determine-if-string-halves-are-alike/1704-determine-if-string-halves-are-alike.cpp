class Solution {
public:
    bool isvowel(char ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U';
    }
    bool halvesAreAlike(string s) {
        int n=s.length();
        int c=0,c1=0;
        for(int i=0;i<n/2;i++){
            if(isvowel(s[i])){
                c++;
            }
        }
        for(int i=n/2;i<n;i++){
             if(isvowel(s[i])){
                c1++;
            }
        }
        return c==c1;
    }
};