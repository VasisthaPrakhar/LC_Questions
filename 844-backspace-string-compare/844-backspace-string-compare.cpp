class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1,s2;
        for(auto x:s){
            if(x=='#'){
                if(s1.length()){
                    s1.pop_back();
                }
            }else{
                s1.push_back(x);
            }
        }
        for(auto x:t){
            if(x=='#'){
                if(s2.length()){
                    s2.pop_back();
                }
            }else{
                s2.push_back(x);
            }
        }
        return s1==s2;
    }
};