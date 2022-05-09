class Solution {
public:
    void fun(vector<string>&ans,string &s,int idx,int &n,unordered_map<char,string>&m,string &d){
        if(idx>=n){
            ans.push_back(s);
            return;
        }
        for(auto &x:m[d[idx]]){
            s.push_back(x);
            fun(ans,s,idx+1,n,m,d);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string d) {
        int n=d.length();
        if(n==0){
            return {};
        }
        unordered_map<char,string>m;
        m['2']="abc";
        m['3']="def";
        m['4']="ghi";
        m['5']="jkl";
        m['6']="mno";
        m['7']="pqrs";
        m['8']="tuv";
        m['9']="wxyz";
        string s="";
        vector<string>ans;
        fun(ans,s,0,n,m,d);
        return ans;
    }
};