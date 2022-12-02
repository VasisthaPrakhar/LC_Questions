class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n=word1.size(),n1=word2.size();
        if(n!=n1){
            return false;
        }
        map<char,int>m,m2;
        for(auto x:word1){
            m[x]++;
        }
        map<int,int>m1;
        for(auto x:m){
            m1[x.second]++;
        }
        for(auto x:word2){
            m2[x]++;
            if(m.find(x)==m.end()){
                return false;
            }
        }
        for(auto x:m2){
            m1[x.second]--;
            if(m1[x.second]==0){
                m1.erase(x.second);
            }
        }
        return m1.size()==0;
    }
};