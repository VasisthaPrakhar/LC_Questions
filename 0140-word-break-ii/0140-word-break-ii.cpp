class Solution {
vector<string>ans;
public:
    bool check(string &s, int n){
        int c=0;
        for(auto &x:s){
            if(x!=' '){
                c++;
            }
        }
        return c==n;
    }
    void fun(int idx,int prev,int n,unordered_set<string>&m,string t,string &s){
        if(idx>=n){
            if(check(t,n))
                ans.push_back(t.substr(0,t.size()-1));
            return;
        }
        string temp=s.substr(prev,idx-prev+1);
        if(m.find(temp)!=m.end()){
            fun(idx+1,idx+1,n,m,t+temp+" ",s);
        }
        fun(idx+1,prev,n,m,t,s);
    }
    vector<string> wordBreak(string s, vector<string>& w) {
        int n=s.length();
        unordered_set<string>m;
        for(auto x:w){
            m.insert(x);
        }
        ans.clear();
        string t="";
        fun(0,0,n,m,t,s);
        return ans;
    }
};