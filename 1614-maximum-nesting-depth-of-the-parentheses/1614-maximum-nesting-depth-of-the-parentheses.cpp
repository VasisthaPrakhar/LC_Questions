class Solution {
public:
    int maxDepth(string s) {
        int n=s.length();
        if(n<=1){return 0;}
        int ans=0,c=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                c++;
            }else if(s[i]==')'){
                ans=max(ans,c);
                c--;
            }
        }
        return ans;
    }
};