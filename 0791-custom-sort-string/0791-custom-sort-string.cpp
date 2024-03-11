class Solution {
public:
    string customSortString(string order, string s) {
        map<char,int>mp;
        for(auto &x:s){
            mp[x]++;
        }
        string ans="";
        for(auto &x:order){
            if(mp.count(x)){
                while(mp[x]){
                    ans.push_back(x);
                    mp[x]--;
                }
                mp.erase(x);
            }
        }
        while(mp.size()){
            auto it=mp.begin();
            int n=it->second;
            while(n){
                ans.push_back(it->first);
                n--;
            }
            mp.erase(it->first);
        }
        return ans;
    }
};