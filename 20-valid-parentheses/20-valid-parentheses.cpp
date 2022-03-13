class Solution {
public:
    bool isValid(string st) {
        if(st.length()%2!=0){
            return false;
        }
        stack<char>s;        
        for(auto x:st){
            if(!s.empty() && ((x==')' && s.top()=='(') || (x==']' && s.top()=='[') || (x=='}' && s.top()=='{'))){
                s.pop();
            }else{
                s.push(x);
            }
        }
        return s.empty();
    }
};