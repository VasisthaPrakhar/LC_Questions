class Solution {
public:
    bool isValid(string st) {
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