class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n=s.length();
        if(n<k){
            return false; 
        }
        unordered_set<string>st;
        for(int i=0;i<n-k+1;i++){
           // cout<<s.substr(i,k);
            st.insert(s.substr(i,k));
        }
        return st.size()==(1<<k);
    }
};