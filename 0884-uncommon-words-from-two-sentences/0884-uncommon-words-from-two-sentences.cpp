class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        stringstream ss(s1);
        string token;
        unordered_map<string,int>mp;
        vector<string>ans;
        while(getline(ss,token,' ')){
            mp[token]++;
        }
        stringstream ss1(s2);
        while(getline(ss1,token,' ')){
            mp[token]++;
        }
        for(auto x:mp){
            if(x.second<=1){
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};