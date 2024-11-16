class Solution {
public:
     bool check(unordered_map<char,int>&m, int tot,int k){
        int ma=0;
        char ch;
        for(auto &x:m){
            if(x.second>ma){
                ma=x.second;
                ch=x.first;
            }
        }
        int rem=tot-ma;
        if(rem>k){return false;}
        return true;
        
    }
    int characterReplacement(string s, int k) {
        int n=s.length();
        unordered_map<char,int>m;
        int i=0,j=0,ans=0;
        while(j<n){
            m[s[j]]++;
            while(i<=j && !check(m,j-i+1,k)){
                m[s[i]]--;
                if(m[s[i]]==0){
                    m.erase(s[i]);
                }
                i++;
            }
            ans=max(j-i+1,ans);
            j++;
        }
        return ans;
    }
};