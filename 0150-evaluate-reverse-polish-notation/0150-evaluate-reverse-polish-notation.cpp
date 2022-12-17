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
                if(x=="+"){
                    string a=s.top();
                    s.pop();
                    string b=s.top();
                    s.pop();
                    ll aa=stoll(a);
                    ll bb=stoll(b);
                    ll c=aa+bb;
                    string k=to_string(c);
                    s.push(k);
                }else if(x=="-"){
                    string a=s.top();
                    s.pop();
                    string b=s.top();
                    s.pop();
                    ll aa=stoll(a);
                    ll bb=stoll(b);
                    ll c=bb-aa;
                    string k=to_string(c);
                    s.push(k);
                }else if(x=="*"){
                    string a=s.top();
                    s.pop();
                    string b=s.top();
                    s.pop();
                    ll aa=stoll(a);
                    ll bb=stoll(b);
                    ll c=aa*bb;
                    string k=to_string(c);
                    s.push(k);
                }else{
                    string a=s.top();
                    s.pop();
                    string b=s.top();
                    s.pop();
                    ll aa=stoll(a);
                    ll bb=stoll(b);
                    ll c=bb/aa;
                    //cout<<c<<"&&&"<<endl;
                    string k=to_string(c);
                    s.push(k);
                }
            }else{
                s.push(x);
            }
            //cout<<s.top()<<" ";
        }
        //cout<<endl;
        return stoll(s.top());
    }
};