class Solution {
public:
    int maxDepth(string s) {
        int n=s.length();
        if(n<=1){return 0;}
        int ans=0;
        stack<char>st;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(s[i]);
            }else if(s[i]==')'){
                ans=max(ans,(int)st.size());
                st.pop();
            }
        }
        return ans;
    }
};