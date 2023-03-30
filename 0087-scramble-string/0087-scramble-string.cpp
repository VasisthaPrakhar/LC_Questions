class Solution {
public:
    unordered_map<string,bool>mp;
    bool fun(string s,string t){
        if(s==t){
            return true;
        }
        int n=s.length();
        if(n!=t.length()){
            return false;
        }
        if(n==1){
            return false;
        }
        string st=s+" "+t;
        if(mp.find(st)!=mp.end()){
            return mp[st];
        }
        for(int i=0;i<n-1;i++){
            if((fun(s.substr(0,i+1),t.substr(0,i+1))&&fun(s.substr(i+1),t.substr(i+1))) || (fun(s.substr(0,i+1),t.substr(n-(i+1)))&&fun(s.substr(i+1),t.substr(0,n-(i+1)))) ){
                return true;
            }
        }
        return mp[st]=false;
    }
    bool isScramble(string s1, string s2) {
        return fun(s1,s2);
    }
};