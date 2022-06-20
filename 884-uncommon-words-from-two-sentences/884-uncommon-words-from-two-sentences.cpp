class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int>s;
        string t;
        stringstream ss(s1),ss1(s2);
        while(getline(ss,t,' ')){
            s[t]++;
        }
        while(getline(ss1,t,' ')){
            s[t]++;
        }
        vector<string>ans;
        for(auto x:s){
            if(x.second==1){
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};