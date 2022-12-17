class Solution {
public:
    typedef long long int ll;
    bool check(string s){
        return s=="/"||s=="-"||s=="+"||s=="*";
    }
    int evalRPN(vector<string>& tokens) {
        stack<string>s;
        int ans=0;
        for(auto x:tokens){
            if(check(x)){
                string a=s.top();
                s.pop();
                string b=s.top();
                s.pop();
                ll aa=stoll(a);
                ll bb=stoll(b),c;
                if(x=="+"){
                    c=aa+bb;
                }else if(x=="-"){
                    c=bb-aa;
                }else if(x=="*"){
                    c=aa*bb;
                }else{
                    c=bb/aa;
                }
                string k=to_string(c);
                s.push(k);
            }else{
                s.push(x);
            }
        }
        return stoll(s.top());
    }
};