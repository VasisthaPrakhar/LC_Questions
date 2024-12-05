class Solution {
public:
    bool canChange(string s, string t) {
        int n=s.length();
        stack<char>l,r;
        for(int i=0;i<n;i++){
            if(s[i]=='R'){
                r.push(s[i]);
            }else if(s[i]=='L'){
                if(!r.empty())
                    return false;
            }
            if(t[i]=='R'){
                if(!r.empty()){
                    r.pop();
                }else{
                    return false;
                }
            }else if(t[i]=='L'){
                if(!r.empty())
                    return false;
            }
        }
        if(r.size()){return false;}
        for(int i=n-1;i>=0;i--){
            if(s[i]=='L'){
                l.push(s[i]);
            }else if(s[i]=='R'){
                if(!l.empty())
                    return false;
            }
            if(t[i]=='L'){
                if(!l.empty()){
                    l.pop();
                }else{
                    return false;
                }
            }else if(t[i]=='R'){
                if(!l.empty())
                    return false;
            }
        }
        if(l.size()){return false;}
        return true;
    }
};