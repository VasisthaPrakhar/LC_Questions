class Solution {
public:
    int fun(int n){
        int a=1;
        while(n--){
            a=a*2;
        }
        return a;
    }
    int scoreOfParentheses(string s) {
        int n=s.length();
        stack<char>st;
        int ans=0;
        for(int i=0;i<n;i++){
            if(!st.empty() && s[i]==')' && st.top()=='('){
                st.pop();
                ans=ans+(st.size()==0?1:fun(st.size()));
                i++;
                while(!st.empty() && s[i]==')' && st.top()=='(' && i<n){
                    st.pop();
                    i++;
                }
                i--;
            }else{
                st.push(s[i]);
            }
        }
        return ans;
    }
};