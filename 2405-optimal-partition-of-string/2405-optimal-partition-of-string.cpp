class Solution {
public:
    int partitionString(string &s) {
        int i=0,j=0,n=s.length(),ans=0;
        unordered_set<char>m;
        while(j<n){
            m.insert(s[j]);
            if(m.size()<(j-i+1)){
                ans++;
                m.clear();
                m.insert(s[j]);
                i=j;
            }
            j++;
        }
        if(m.size()>0){
            ans++;
        }
        return ans;
    }
};