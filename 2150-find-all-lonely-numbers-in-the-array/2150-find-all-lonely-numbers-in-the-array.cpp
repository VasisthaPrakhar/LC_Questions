class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        map<int,int>s;
        vector<int>ans;
        for(const auto &x:nums){
            s[x]++;
        }
        for(const auto &x:s){
            int node=x.first;
            if(x.second==1 && !s.count(node+1) && !s.count(node-1)){
                ans.push_back(node);
            }
        }
        return ans;
    }
};