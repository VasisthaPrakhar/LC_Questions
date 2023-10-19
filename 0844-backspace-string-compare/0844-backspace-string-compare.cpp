class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>st;
        for(auto x:s){
            if(x=='#'){
                if(st.size())
                    st.pop();
            } else{
                st.push(x);
            }
        }
        string a="",b="";
        while(!st.empty()){
            a.push_back(st.top());
            st.pop();
        }
         for(auto x:t){
            if(x=='#'){
                if(st.size())
                    st.pop();
            } else{
                st.push(x);
            }
        }
         while(!st.empty()){
            b.push_back(st.top());
            st.pop();
        }
        return a==b;
    }
};