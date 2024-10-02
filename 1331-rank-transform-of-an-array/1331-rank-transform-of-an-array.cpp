class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int>mp,mp1;
        for(auto x:arr){
            mp[x]++;
        }
        int k=1;
        for(auto x:mp){
            mp1[x.first]=k++;
        }
        vector<int>ans;
        for(auto x:arr){
            ans.push_back(mp1[x]);
        }
        return ans;
    }
};