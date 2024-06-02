class Solution {
public:
    string clearStars(string s) {
        int n=s.length();
        map<char,vector<int>>mp;
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                auto it=mp.begin();
                it->second.pop_back();
                if(it->second.size()==0){
                    mp.erase(it->first);
                }
            }else{
                mp[s[i]].push_back(i);
            }
        }
        map<int,char>temp;
        for(auto x:mp){
            for(auto y:x.second){
                temp[y]=x.first;
            }
        }
        string ans="";
        for(auto x:temp){
            ans.push_back(x.second);
        }
        return ans;
    }
};