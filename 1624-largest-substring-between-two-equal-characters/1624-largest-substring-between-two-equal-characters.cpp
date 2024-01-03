class Solution {
public:
    int maxLengthBetweenEqualCharacters(string &s) {
        int n=s.length();
        map<char,vector<int>>m;
        for(int i=0;i<n;i++){
            m[s[i]].push_back(i);
        }
        int ans=-1;
        for(auto x:m){
            if(x.second.size()>1){
                ans=max(ans,x.second.back()-x.second[0]-1);
            }
        }
        return ans;
    }
};