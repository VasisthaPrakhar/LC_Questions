class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int,greater<int>>mp,mp1;
        for(auto &x:nums){
            mp[x]++;
        }
        for(auto &x:mp){
            mp1[x.second]++;
        }
        return (mp1.begin()->first)*(mp1.begin()->second);
    }
};