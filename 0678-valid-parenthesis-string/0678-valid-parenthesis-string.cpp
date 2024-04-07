class Solution {
public:
    
    bool fun(int idx, int n, string &s, int k, unordered_map<int,unordered_map<int,bool>>&m){
        if(idx>=n){
            if(k==0){return true;}
            return false;
        }
        if(m.find(idx)!=m.end()){
            if(m[idx].find(k) != m[idx].end()){
                return m[idx][k];
            }
        }
        bool res=false;
        if(s[idx]=='('){
            res|=fun(idx+1,n,s,k+1,m);
        }else if(s[idx]==')'){
            if(k>0)
                res|=fun(idx+1,n,s,k-1,m);
        }else{
            res|=fun(idx+1,n,s,k+1,m);
            if(k>0){
                res|=fun(idx+1,n,s,k-1,m);
            }
            res|=fun(idx+1,n,s,k,m);
        }
        return m[idx][k] = res;
    }
    bool checkValidString(string &s) {
        int n=s.length();
        unordered_map<int,unordered_map<int,bool>>m;
        return fun(0,n,s,0,m);
    }
};