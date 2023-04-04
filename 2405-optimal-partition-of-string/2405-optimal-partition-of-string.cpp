class Solution {
public:
    int partitionString(string s) {
        int i=0,j=0,n=s.length(),ans=0;
        unordered_map<char,int>m;
        while(j<n){
            m[s[j]]++;
            if(m.size()<(j-i+1)){
                ans++;
                m.clear();
                m[s[j]]++;
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