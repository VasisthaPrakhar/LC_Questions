class Solution {
public:
    int minPartitions(string s) {
        int n=s.length(),m=0;
        for(int i=0;i<n;i++){
            m=max(m,s[i]-'0');
        }
        return m;
    }
};