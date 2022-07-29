class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& w, string p) {
        int n=w.size(),m=p.length();
        vector<string>ans;
        unordered_map<char,int>mp;
        unordered_set<char>s;
        for(auto x:p){
            s.insert(x);
        }
        int k=s.size();
        for(int i=0;i<n;i++){
            mp.clear();
            s.clear();
            int f=1;
            for(int j=0;j<m;j++){
                if(mp.count(p[j])){
                    if(mp[p[j]]!=w[i][j]){
                        f=0;
                        break;
                    }
                }else{
                    mp[p[j]]=w[i][j];
                    s.insert(w[i][j]);
                }
            }
            if(f==1 && s.size()==k){
                ans.push_back(w[i]);
            }
        }
        return ans;
    }
};