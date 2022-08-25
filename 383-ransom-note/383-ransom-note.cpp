class Solution {
public:
    bool canConstruct(string r, string ma) {
        int n=r.length();
        int m=ma.length();
        if(n>m){
            return false;
        }
        vector<int>a(26,0);
        for(auto x:ma){
            a[x-'a']++;
        }
        for(auto x:r){
            if(a[x-'a']<=0){
                return false;
            }else{
                a[x-'a']--;
            }
        }
        return true;
    }
};