class Solution {
public:
    bool fun(string &s,int i,int j){
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++,j--;
        }
        return true;
    }
    int countSubstrings(string s) {
        int n=s.length();
        if(n==1){
            return 1;
        }
        int ans=0;
        map<char,unordered_set<int>>m;
        for(int i=0;i<n;i++){
            m[s[i]].insert(i);
        }
        for(int i=0;i<n;i++){
            for(auto x:m[s[i]]){
                if(fun(s,i,x)){
                    ans++;
                }
            }
            m[s[i]].erase(i);
            if(m[s[i]].size()==0){
                m.erase(s[i]);
            }
        }
        return ans;
    }
};