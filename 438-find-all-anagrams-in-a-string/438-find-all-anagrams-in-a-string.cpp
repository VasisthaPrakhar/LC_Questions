class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.length();
        int m=p.length();
        if(m>n){
            return {};
        }
        vector<int>mp(26,0),mp1(26,0),ans;
        for(auto x:p){
            mp[x-'a']++;
        }
        int f=1;
        for(int i=0;i<n-m+1;i++){
            string temp=s.substr(i,m);
            if(f==1){
                for(auto x:temp){
                    mp1[x-'a']++;
                }
                f++;
            }else{
                mp1[s[i-1]-'a']--;
                mp1[s[i+m-1]-'a']++;
            }
            if(mp1==mp){
                ans.push_back(i);
            }
        }
        return ans;
    }
};