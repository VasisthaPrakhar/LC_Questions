class Solution {
public:
    vector<string> sortPeople(vector<string>& na, vector<int>& h) {
        int n=na.size();
        vector<pair<int,string>>v;
        for(int i=0;i<n;i++){
            v.push_back({h[i],na[i]});
        }
        sort(v.begin(),v.end(),greater<pair<int,string>>());
        vector<string>ans;
        for(auto x:v){
            ans.push_back(x.second);
        }
        return ans;
    }
};