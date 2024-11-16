class Solution {
public:
    bool check(unordered_map<char,int>&m1, unordered_map<char,int>&m2, int tot,int k){
        int ma=0;
        char ch;
        for(auto x:m2){
            if(x.second>ma){
                ma=x.second;
                ch=x.first;
            }
        }
        int rem=tot-ma;
        if(rem>k){return false;}
        if(m1[ch]<tot){
            return false;
        }
        return true;
        
    }
    int maxRepOpt1(string &s) {
        int n=s.length();
        unordered_map<char,int>m1,m2;
        for(auto x:s){
            m1[x]++;
        }
        int i=0,j=0,ans=0;
        while(j<n){
            m2[s[j]]++;
            while(i<=j && !check(m1,m2,j-i+1,1)){
                m2[s[i]]--;
                if(m2[s[i]]==0){
                    m2.erase(s[i]);
                }
                i++;
            }
            ans=max(j-i+1,ans);
            j++;
        }
        return ans;
    }
};